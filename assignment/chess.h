/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: 2DHIF
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			chess.h
 * Author:			Michael Enkner
 * Due Date:		October 15, 2014
 * ----------------------------------------------------------
 * Description:
 * Basic chess functions.
 * ----------------------------------------------------------
 */
 #include <stdbool.h>

 #ifndef ___CHESS_H
 #define ___CHESS_H

enum PieceColor { White, Black };

enum PieceType{
  Pawn, Knight, Rook, Bishop, Queen, King, NoPiece
};

enum MoveType{
  NormalMove, CaptureMove
};

struct ChessPiece{
  enum PieceColor color;
  enum PieceType type;
};

struct ChessSquare{
  bool is_occupied;
  struct ChessPiece piece;
};

typedef struct ChessSquare ChessBoard[8][8];
typedef char File;
typedef int Rank;

bool is_piece(struct ChessPiece board ,enum PieceColor color, enum PieceType type);

void init_chess_board(ChessBoard chess_board);

ChessSquare* get_square(ChessBoard chess_board, int file, int rank);

bool is_square_occupied(ChessBoard chess_board, int file, int rank);

bool add_piece(ChessBoard chess_board, char a, int rank, struct ChessPiece black_rook);

ChessPiece get_piece(ChessBoard chess_board,char a, int rank);

void setup_chess_board(ChessBoard chess_board);

bool remove_piece(ChessBoard chess_board, File file,Rank rank);

bool squares_share_file(File file, Rank rank, File file02, Rank rank02);

bool squares_share_rank(File file, Rank rank, File file02, Rank rank02);

bool squares_share_diagonal(File file, Rank rank, File file02, Rank rank02);

bool squares_share_knights_move(File file, Rank rank, File file02, Rank rank02);

bool squares_share_pawns_move (enum PieceColor color, enum MoveType move, File file, Rank rank, File file02, Rank rank02);

bool squares_share_kings_move(File file, Rank rank, File file02, Rank rank02);

bool squares_share_queens_move(File file, Rank rank, File file02, Rank rank02);

#endif
