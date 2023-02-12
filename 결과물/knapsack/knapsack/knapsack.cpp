#include <iostream>
#include <algorithm>
using namespace std;

int n = 0;// ���� ����
int W = 0;// ��� ������ �Ѱ�
int v_arr[6] = {0};// ������ ���� ��ġ�� ������ �迭
int w_arr[6] = {0};//������ ���� ���Ը� ������ �迭
int profit[7][7] = {0,};// ���̳��� ���α׷��� ������ ������ 2���� �迭

void Knapsack_Dynamic_programing()
{
    for (int i = 1; i <= n; i++)
    {
        // i�� item�� ������ ��Ÿ���� i�� 1�� ������Ű�� ǥ�� �ϼ���Ű�� ����. 
        for (int j = 1; j <= W; j++)
        {
            //j�� ���� ������ �ִ밪���� �ΰ� j�� 1�� ������Ű�� ǥ�� �ϼ���Ű�� ����
            if (w_arr[i] <= j)//���� ���� ���� �� ���� ��
            {
                //ǥ�� ��ĭ�� ���� (�������� ��ġ+ǥ���� i-1���� �賶 ���� �Ѱ� - ���� ���� ���Կ��� ���� ������)�� �� �ִ밪�� �����Ѵ�.
                profit[i][j] = max(profit[i - 1][j - w_arr[i]] + v_arr[i], profit[i - 1][j]);
            }
            else// ���� ���� ���� �� ���� ��
            {
                //ǥ�� ��ĭ�� ���� �����´�.
                profit[i][j] = profit[i - 1][j];
            }
        }
    }
}

int main()
{
    // item ������, �� item�� worth, weigh  �׸��� �賶 ���� �Ѱ踦 �����Ѵ�.
    cout << "Enter the number of items: ";
    cin >> n;
    if ((n < 0) || (n > 5))//����ó�� 
    {
        cout << "Error \n";
        return 0;
    }
    for (int k = 1; k <= n; k++)
    { 
        cout << "Enter" << " " << k << "'s" << " " << "worth: ";
        cin >> v_arr[k];
        if ((v_arr[k] < 1) || (v_arr[k] > 50))//����ó�� 
        {
            cout << "Error \n";
            return 0;

        }
        cout << "Enter"<<" "<<k<<"'s"<<" "<< "weight: ";
        cin >> w_arr[k];
        if ((w_arr[k] < 1) || (w_arr[k] > 5))//����ó�� 
        {
            cout << "Error \n";
            return 0;

        }
    }

    cout << "insert maximum weigth: ";
    cin >> W;
    if ((W < 0) || (W > 5))//����ó�� 
    {
        cout << "Error \n";
        return 0;

    }
    Knapsack_Dynamic_programing();// optimal value�� ã�� �Լ� ����
    cout << "-------------------------------------\n";
    cout << "the value (in dollars) of an optimal solution to the 0-1 knapsack problem for inputs: " << profit[n][W] << '\n';// �Լ��� ���� ������ 2�����迭(ǥ)���� item������ �賶 ���Կ����� �Է¹��� n�� W�� ���� �������� �װ� ���̴�.

    return 0;
}