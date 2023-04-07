#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int   min_row, max_row; // 바꿀 row
int   min_col, max_col; // 바꿀 col
long long   N, M;
long long   A[1005][1005];
long long   B[1005][1005];

long long   sumB(void)
{
   long long   result;

   result = 0;
   for (int i=0; i<N-1; i++)
      for (int j=0; j<M-1; j++)
         result += B[i][j];
   return (result);
}

void   makeB(void)
{
   for (int i=0; i<N-1; i++)
   {
      for (int j=0; j<M-1; j++)
      {
         B[i][j] = A[i][j] + A[i + 1][j] + A[i + 1][j + 1] + A[i][j + 1];
      }
   }
}

long long   max_gap_row(void)
{
   long long   sum, max_edge_sum, edge_sum_1, edge_sum_2;
   long long   min_mid_sum;

   min_mid_sum = 987654321;
   
   edge_sum_1 = A[0][0] + A[0][M-1];
   for (int j=1; j<M-1; j++)
      edge_sum_1 += 2*A[0][j];
      
   edge_sum_2 = A[N-1][0] + A[N-1][M-1];
   for (int j=1; j<M-1; j++)
      edge_sum_2 += 2*A[N-1][j];
      
   if (edge_sum_1 < edge_sum_2){
      max_edge_sum = edge_sum_2;
      max_row = N-1;
   }else{
      max_edge_sum = edge_sum_1;
      max_row = 0;
   }
   
   for (int i=1; i<N-1; i++)
   {
      sum = A[i][0] + A[i][M-1];
      for (int j=1; j<M-1; j++)
         sum += 2*A[i][j];

      if (sum < min_mid_sum){
         min_mid_sum = sum;
         min_row = i;
      }
   }
   
   return (max_edge_sum - min_mid_sum);
}

long long   max_gap_col(void)
{
   long long   sum, max_edge_sum, edge_sum_1, edge_sum_2;
   long long   min_mid_sum;

   min_mid_sum = 987654321;
   
   edge_sum_1 = A[0][0] + A[N-1][0];
   for (int j=1; j<N-1; j++)
      edge_sum_1 += 2*A[j][0];
      
   edge_sum_2 = A[0][M-1] + A[N-1][M-1];
   for (int j=1; j<N-1; j++)
      edge_sum_2 += 2*A[j][M-1];
      
   if (edge_sum_1 < edge_sum_2){
      max_edge_sum = edge_sum_2;
      max_col = M-1;
   }else{
      max_edge_sum = edge_sum_1;
      max_col = 0;
   }
   
   for (int i=1; i<M-1; i++)
   {
      sum = A[0][i] + A[N-1][i];
      for (int j=1; j<N-1; j++)
         sum += 2*A[j][i];
      
      if (sum < min_mid_sum){
         min_mid_sum = sum;
         min_col = i;
      }
   }
   
   return (max_edge_sum - min_mid_sum);
}

void   swap_row(int row1, int row2)
{
   long long   temp;

   for (int i=0; i<M; i++)
   {
      temp = A[row1][i];
      A[row1][i] = A[row2][i];
      A[row2][i] = temp;
   }
}

void   swap_col(int col1, int col2)
{
   long long   temp;

   for (int i=0; i<N; i++)
   {
      temp = A[i][col1];
      A[i][col1] = A[i][col2];
      A[i][col2] = temp;
   }
}

// 1 2 2 2 2 1
// 2 4 4 4 4 2
// 2 4 4 4 4 2
// 2 4 4 4 4 2
// 2 4 4 4 4 2
// 2 4 4 4 4 2
// 1 2 2 2 2 1
// 의 형태로 각 원소가 사용될 것이다.
// 가운데에 들어가는 라인에 대한 크기가 커야함
// row_gap과 col_gap을 비교해서 gap이 더 큰 애들을 바꾸면 될 듯?
int   main(void)
{   
   long long   row_gap, col_gap;

   cin >> N >> M;
   for (int i=0; i<N; i++)
      for (int j=0; j<M; j++)
         cin >> A[i][j];
   min_row = max_row = min_col = max_col = -1;
   row_gap = max_gap_row();
   col_gap = max_gap_col();
   if (row_gap < col_gap){
      if (col_gap > 0)
         swap_col(min_col, max_col);
   }
   else{
      if (row_gap > 0){
         swap_row(min_row, max_row);
      }
   }
   makeB();
// Debug Code
   // cout << "row_gap: " << row_gap << " col_gap: " << col_gap << '\n' << '\n';
   // cout << "row_index: " << min_row << " " << max_row << ", col_index: " << min_col << " " << max_col << '\n' << '\n';
   // for (int i=0; i<N; i++)
   // {
   //    for (int j=0; j<M; j++)
   //       cout << A[i][j] << " ";
   //    cout << '\n';
   // }
   cout << sumB();
}