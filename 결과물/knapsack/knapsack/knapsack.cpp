#include <iostream>
#include <algorithm>
using namespace std;

int n = 0;// 짐의 개수
int W = 0;// 배방 무게의 한계
int v_arr[6] = {0};// 각각의 짐의 가치를 저장할 배열
int w_arr[6] = {0};//각각의 짐의 무게를 저장할 배열
int profit[7][7] = {0,};// 다이나믹 프로그래밍 과정을 저장할 2차원 배열

void Knapsack_Dynamic_programing()
{
    for (int i = 1; i <= n; i++)
    {
        // i는 item의 순번을 나타내며 i를 1씩 증가시키며 표를 완성시키는 과정. 
        for (int j = 1; j <= W; j++)
        {
            //j를 가방 무게의 최대값으로 두고 j를 1씩 증가시키며 표를 완성시키는 과정
            if (w_arr[i] <= j)//현재 짐을 넣을 수 있을 때
            {
                //표의 위칸의 값과 (현재짐의 가치+표에서 i-1행의 배낭 무게 한계 - 현재 짐의 무게열의 값을 가져옴)값 중 최대값을 선택한다.
                profit[i][j] = max(profit[i - 1][j - w_arr[i]] + v_arr[i], profit[i - 1][j]);
            }
            else// 현재 짐을 넣을 수 없을 때
            {
                //표의 위칸의 값을 가져온다.
                profit[i][j] = profit[i - 1][j];
            }
        }
    }
}

int main()
{
    // item 개수와, 각 item의 worth, weigh  그리고 배낭 무게 한계를 설정한다.
    cout << "Enter the number of items: ";
    cin >> n;
    if ((n < 0) || (n > 5))//예외처리 
    {
        cout << "Error \n";
        return 0;
    }
    for (int k = 1; k <= n; k++)
    { 
        cout << "Enter" << " " << k << "'s" << " " << "worth: ";
        cin >> v_arr[k];
        if ((v_arr[k] < 1) || (v_arr[k] > 50))//예외처리 
        {
            cout << "Error \n";
            return 0;

        }
        cout << "Enter"<<" "<<k<<"'s"<<" "<< "weight: ";
        cin >> w_arr[k];
        if ((w_arr[k] < 1) || (w_arr[k] > 5))//예외처리 
        {
            cout << "Error \n";
            return 0;

        }
    }

    cout << "insert maximum weigth: ";
    cin >> W;
    if ((W < 0) || (W > 5))//예외처리 
    {
        cout << "Error \n";
        return 0;

    }
    Knapsack_Dynamic_programing();// optimal value를 찾는 함수 실행
    cout << "-------------------------------------\n";
    cout << "the value (in dollars) of an optimal solution to the 0-1 knapsack problem for inputs: " << profit[n][W] << '\n';// 함수를 통해 변경한 2차원배열(표)에서 item개수행 배낭 무게열에서 입력받은 n행 W열 값을 가져오면 그게 답이다.

    return 0;
}