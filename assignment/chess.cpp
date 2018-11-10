/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: 2AHDV
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			chess.c
 * Author:			P. Bauer
 * Due Date:		November 03, 2010
 * ----------------------------------------------------------
 * Description:
 * Implementation of basic chess functions.
 * ----------------------------------------------------------
 */
 #include <stdlib.h>
 #include "general.h"
 #include "chess.h"

  //bool 	is_square_ok (File file, Rank rank);
  //int 	nr (Rank rank);
  //int 	nf (File file);
  //bool 	is_move_from_base_line (enum PieceColor color, Rank rank);

  bool is_piece(struct ChessPiece board ,enum PieceColor color, enum PieceType type)
 {
   return(board.type == type && board.color == color);
 }

  ChessSquare* get_square(ChessBoard chess_board, int file, int rank)
  {
    if((file > 'h' || file < 'a') || (rank > 8 || rank < 1))
    {
      return 0;
    }
    return &chess_board[rank-1][file-97];

  }

  bool is_square_occupied(ChessBoard chess_board, int file, int rank)
  {
    int int_file = file - 97;

    return chess_board[rank-1][int_file].is_occupied;
  }

  bool add_piece(ChessBoard chess_board, char a, int rank, struct ChessPiece piece)
  {
    if((a > 'h' || a < 'a') || (rank > 8 || rank < 1) || chess_board[rank-1][a - 97].is_occupied)
    {
      return false;
    }

    chess_board[rank-1][a - 97].is_occupied = true;
    chess_board[rank-1][a -97].piece = piece;

    return true;

  }

  struct ChessPiece get_piece(ChessBoard chess_board,char a, int rank)
  {
    if(((a > 'h' || a < 'a') || (rank > 8 || rank < 1)) || chess_board[rank-1][a-97].is_occupied == false)
    {
      chess_board[rank-1][a-97].piece.type = NoPiece;
      return chess_board[rank-1][a-97].piece;
    }
 return chess_board[rank-1][a-97].piece;
  }


  void init_chess_board(ChessBoard chess_board)
  {
    for (int i = 0; i < 8; i++) {

      for (int j = 0; j < 8; j++) {

        chess_board[i][j].is_occupied = false;

        chess_board[i][j].piece.type = NoPiece;

      }
    }
  }

  void setup_chess_board(ChessBoard chess_board)
  {

    init_chess_board(chess_board);

    File file;

    for (file = 'a'; file <= 'h'; file++) {
          add_piece(chess_board, file, 2, {White,Pawn});
          add_piece(chess_board, file, 7, {Black, Pawn});
        }

    add_piece(chess_board, 'a', 1, {White, Rook});
    add_piece(chess_board, 'h', 1, {White, Rook});
    add_piece(chess_board, 'b', 1, {White, Knight});
    add_piece(chess_board, 'g', 1, {White, Knight});
    add_piece(chess_board, 'c', 1, {White, Bishop});
    add_piece(chess_board, 'f', 1, {White, Bishop});
    add_piece(chess_board, 'd', 1, {White, Queen});
    add_piece(chess_board, 'e', 1, {White, King});
    add_piece(chess_board, 'a', 8, {Black, Rook});
    add_piece(chess_board, 'h', 8, {Black, Rook});
    add_piece(chess_board, 'b', 8, {Black, Knight});
    add_piece(chess_board, 'g', 8, {Black, Knight});
    add_piece(chess_board, 'c', 8, {Black, Bishop});
    add_piece(chess_board, 'f', 8, {Black, Bishop});
    add_piece(chess_board, 'd', 8, {Black, Queen});
    add_piece(chess_board, 'e', 8, {Black, King});
  }

  bool remove_piece(ChessBoard chess_board, File file,Rank rank)
  {
    if(file - 97 > 8 || file - 97 < 0 || rank > 8 || rank < 0 || chess_board[rank - 1][file - 97].is_occupied == true)
    {
      chess_board[rank-1][file - 97].is_occupied = false;
      chess_board[rank-1][file - 97].piece.type = NoPiece;

      return true;
    }
    return false;
  }

  bool squares_share_file(File file, Rank rank, File file02, Rank rank02)
  {
    if (rank > 8 || rank < 1 || rank02 > 8 || rank02 < 1|| file < 'a' || file > 'h' || file02 < 'a' || file02 > 'h')
    {
      return false;
    }
    return (file == file02);
  }

  bool squares_share_rank(File file, Rank rank, File file02, Rank rank02)
  {
    if (rank > 8 || rank < 1 || rank02 > 8 || rank02 < 1|| file < 'a' || file > 'h' || file02 < 'a' || file02 > 'h')
    {
      return false;
    }
    return(rank == rank02);
  }

  bool squares_share_diagonal(File file, Rank rank, File file02, Rank rank02)
  {
   if (rank > 8 || rank < 1 || rank02 > 8 || rank02 < 1|| file < 'a' || file > 'h' || file02 < 'a' || file02 > 'h')
   {
     return false;
   }
   int dv;
   int dh;
   if (file - file02 < 0)
   {
     dv = (file - file02) * -1;
   }
   if (dh = rank - rank02 < 0)
   {
     dh = (rank - rank02) * -1;
   }
   return dh = dv;
  }

  bool squares_share_knights_move(File file, Rank rank, File file02, Rank rank02)
  {
    if (rank > 8 || rank < 1 || rank02 > 8 || rank02 < 1|| file < 'a' || file > 'h' || file02 < 'a' || file02 > 'h')
    {
      return false;
    }
    return ()
  }

  bool squares_share_pawns_move (enum PieceColor color, enum MoveType move, File file, Rank rank, File file02, Rank rank02)
  {
    if (rank > 8 || rank < 1 || rank02 > 8 || rank02 < 1|| file < 'a' || file > 'h' || file02 < 'a' || file02 > 'h')
    {
      return false;
    }
  }

  bool squares_share_kings_move(File file, Rank rank, File file02, Rank rank02)
  {
    if (rank > 8 || rank < 1 || rank02 > 8 || rank02 < 1|| file < 'a' || file > 'h' || file02 < 'a' || file02 > 'h')
    {
      return false;
    }
    return squares_share_file(file,rank,file02,rank02) || squares_share_rank(file,rank,file02,rank02) || squares_share_diagonal(file,rank,file02,rank02);
  }

  bool squares_share_queens_move(File file, Rank rank, File file02, Rank rank02)
  {
    if (rank > 8 || rank < 1 || rank02 > 8 || rank02 < 1|| file < 'a' || file > 'h' || file02 < 'a' || file02 > 'h')
    {
      return false;
    }
    return squares_share_file(file,rank,file02,rank02) || squares_share_rank(file,rank,file02,rank02) || squares_share_diagonal(file,rank,file02,rank02);
  }
