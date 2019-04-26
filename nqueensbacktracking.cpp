#include<iostream>
#define N 4
using namespace std;

void printPlacement(int chess_board[N][N]) {
   int i,j;
   cout<<"\nPlacement of N queens :-\n";
   for (i = 0; i < N; i++) {
      for (j = 0; j < N; j++) {
           cout<<chess_board[i][j]<<" ";
      }
      cout<<endl;
   }
}

bool isCellSafe(int chess_board[N][N], int r_idx, int c_idx) {
   int i, j;

   for (i = 0; i < c_idx; i++) {
      if (chess_board[r_idx][i] == 1) {
         return false;
      }
   }

   i = r_idx; j = c_idx;
   while (i >= 0 && j >= 0) {
      if (chess_board[i][j] == 1) {
         return false;
      }
      i--; j--;
   }

   i = r_idx; j = c_idx;
   while (i < N && j >= 0) {
      if (chess_board[i][j] == 1) {
         return false;
      }
      i++; j--;
   }
   return true;
}

bool placeNQueens(int chess_board[N][N], int c_idx) {
   if (c_idx >= N) {
      return true;
   }

   int i;
   for (i = 0; i < N; i++) {
      if (isCellSafe(chess_board, i, c_idx)) {
         chess_board[i][c_idx] = 1;

         if (placeNQueens(chess_board, c_idx + 1) == true )
            return true;
         chess_board[i][c_idx] = 0;
      }
   }
   return false;
}


int main() {
   int chess_board[N][N] = { {0, 0, 0, 0},
                             {0, 0, 0, 0},
                             {0, 0, 0, 0},
                             {0, 0, 0, 0} };
   bool n_queens_sol = placeNQueens(chess_board,0);
   if (n_queens_sol == false) {
      cout<<"\n N queens placement not possible";
   }
   else {
      cout<<"\n N queens can be placed on NxN chessboard";
      printPlacement(chess_board);
   }
   cout<<endl;
   return 0;
}
