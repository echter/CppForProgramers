#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class ChessBoard {
public:
    enum class Color { WHITE,
        BLACK };

    class Piece {
    private:
        std::string _type_short;
    public:
        Piece(Color color, std::string type_short) : color(color), _type_short(type_short) {}
        virtual ~Piece() {}

        Color color;
        std::string color_string() const {
            if (color == Color::WHITE)
                return "white";
            else
                return "black";
        }

        std::string type_short() {
            if (_type_short.length() > 2)
                _type_short = _type_short.substr(0, 2);
            else if (_type_short.length() < 2)
                _type_short = _type_short + " ";
            return color_string().substr(0, 1) + _type_short;
        }

        /// Return color and type of the chess piece
        virtual std::string type() const = 0;

        /// Returns true if the given chess piece move is valid
        virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const = 0;
    };

    class King : public Piece {
    private:
        std::string _type = "King";
    public:
        King(Color color) : Piece(color, "Ki"){}

        std::string type() const override {
            return color_string() + " " + _type;
        }

        bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
            return std::abs(to_x - from_x == 1) || std::abs(to_y - from_y == 1);
        }
    };

    class Knight : public Piece {
    private:
        std::string _type = "Knight";
    public:
        Knight(Color color) : Piece(color, "Kn"){}

        std::string type() const override {
            return color_string() + " " + _type;
        }

        bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
            return (std::abs(to_x - from_x) == 2 && std::abs(to_y - from_y) == 1) || (std::abs(to_x - from_x) == 1 && std::abs(to_y - from_y) == 2);
        }
    };

    ChessBoard() {
        // Initialize the squares stored in 8 columns and 8 rows:
        squares.resize(8);
        for (auto &square_column : squares)
            square_column.resize(8);
    }

    /// 8x8 squares occupied by 1 or 0 chess pieces
    vector<vector<shared_ptr<Piece>>> squares;


    function<void(const Piece &piece, const string &from, const string &to)> onPieceMove;
    function<void(const Piece &piece, const string &square)> onPieceRemoved;
    function<void(Color color)> onLostGame;
    function<void(const vector<vector<shared_ptr<ChessBoard::Piece>>> &squares)> afterPieceMove;
    function<void(const Piece &piece, const string &from, const string &to)> onInvalidMove;
    function<void(const string &square)> onMoveMissing;

    /// Move a chess piece if it is a valid move
    bool move_piece(const std::string &from, const std::string &to) {
        int from_x = from.at(0) - 'a';
        int from_y = stoi(string() + from.at(1)) - 1;
        int to_x = to.at(0) - 'a';
        int to_y = stoi(string() + to.at(1)) - 1;

        auto &piece = squares.at(from_x).at(from_y);
        if (piece) {
            if (piece->valid_move(from_x, from_y, to_x, to_y)) {
                if (onPieceMove)
                    onPieceMove(*piece, from, to);
                auto &piece_at_to_pos = squares.at(to_x).at(to_y);
                if (piece_at_to_pos) {
                    if (piece->color != piece_at_to_pos->color) {
                        if (onPieceMove) onPieceMove(*piece, from, to);
                        if (auto king = dynamic_cast<King *>(piece_at_to_pos.get()))
                            if(onLostGame) onLostGame(king->color);
                    } else {
                        // piece in the from square has the same color as the piece in the to square
                        if(onInvalidMove) onInvalidMove(*piece, from, to);
                        return false;
                    }
                }
                piece_at_to_pos = move(piece);
                if(afterPieceMove) afterPieceMove(squares);
                return true;
            } else {
                if(onInvalidMove) onInvalidMove(*piece, from, to);
                return false;
            }
        } else {
            if(onMoveMissing) onMoveMissing(from);
            return false;
        }
    }

    class ChessBoardPrint{
    private:
        ChessBoard &chessBoard;
    public:
        ChessBoardPrint(ChessBoard &board) : chessBoard(board) {

            chessBoard.afterPieceMove = [](const vector<vector<shared_ptr<ChessBoard::Piece>>> &squares){

                int i = 0;
                int j = 0;
                for (auto &column : squares) {
                    char col = i + 65;
                    for (auto &cell : column) {
                        auto piece = cell.get();
                        cout << col << ++j << ":" << " ";
                        if (piece)
                            cout << piece->type_short() << " ";
                        else
                            cout << "    ";
                    }
                    cout << endl;
                    i++;
                    j = 0;
                }
            };

            chessBoard.onPieceRemoved = [](const ChessBoard::Piece &piece, const string &square) {
                cout << piece.type() << " is being removed from " << square << endl;
            };

            chessBoard.onLostGame = [](ChessBoard::Color color) {
                if (color == ChessBoard::Color::WHITE)
                    cout << "Black";
                else
                    cout << "White";
                cout << " won the game" << endl;
            };

            chessBoard.onPieceMove = [](const ChessBoard::Piece &piece, const string &from, const string &to) {
                cout << piece.type() << " is moving from " << from << " to " << to << endl;
            };

            chessBoard.onInvalidMove = [](const ChessBoard::Piece &piece, const string &from, const string &to) {
                cout << "can not move " << piece.type() << " from " << from << " to " << to << endl;
            };

            chessBoard.onMoveMissing = [](const string &square) {
                cout << "no piece at " << square << endl;
            };
        }
    };
};

int main() {
    ChessBoard board;

    //board.squares.at(4).at(0) is the same as board.squares[4][0] but with range check
    board.squares.at(4).at(0) = make_unique<ChessBoard::King>(ChessBoard::Color::WHITE);
    board.squares.at(1).at(0) = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);
    board.squares.at(6).at(0) = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);

    board.squares.at(4).at(7) = make_unique<ChessBoard::King>(ChessBoard::Color::BLACK);
    board.squares.at(1).at(7) = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);
    board.squares.at(6).at(7) = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);

    ChessBoard::ChessBoardPrint printer = ChessBoard::ChessBoardPrint(board);

    cout << "Invalid moves:" << endl;
    board.move_piece("e3", "e2");
    board.move_piece("e1", "e3");
    board.move_piece("b1", "b2");
    cout << endl;

    cout << "A simulated game:" << endl;
    board.move_piece("e1", "e2");
    board.move_piece("g8", "h6");
    board.move_piece("b1", "c3");
    board.move_piece("h6", "g8");
    board.move_piece("c3", "d5");
    board.move_piece("g8", "h6");
    board.move_piece("d5", "f6");
    board.move_piece("h6", "g8");
    board.move_piece("f6", "e8");
}
