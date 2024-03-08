class Solution
{
public:
    int distMoney(int money, int children)
    {
        int n, m, k, mx;

        n = money;
        m = children;
        mx = m;
        int total = 0;
        k = m * 8;

        if (k > n)
        {
            int temp = n;
            temp -= m;

            while (temp > 0 && total <= m)
            {

                if (temp >= 7)
                {
                    // cout << temp << " " << total << " " << m << endl;
                    if ((temp - 7) == 3 && total + 1 == m - 1)
                    {
                        break;
                    }
                    total++;
                    temp -= 7;
                }
                else
                {
                    break;
                }
            }
            mx = total;
        }
        else if (k < n)
        {
            mx--;
        }

        if ((n == 4 && m == 1) || (n < m))
        {
            return -1;
        }
        else
        {
            return mx;
        }
    }
};