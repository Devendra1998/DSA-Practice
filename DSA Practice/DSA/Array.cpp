#include <iostream>
using namespace std;
#define int long long int
#define endl "\n"
int a[10000008];

int BinarySearch(int arr[], int start, int end)
{
    int n = end;
    int ans = 0;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == 0)
        {
            ans = max(ans, mid);
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return n - ans;
}

void SubArraySum(vector<int> arr, int s)
{

    int count = arr.size();
    int curr_sum = arr[0];
    int start = 0;
    for (int i = 1; i <= count; i++)
    {
        while (curr_sum > s && start < i - 1)
        {
            curr_sum -= arr[start];
            start++;
        }
        if (curr_sum == s)
        {
            cout << start + 1 << " " << i;
            return;
        }
        if (i < count)
        {
            curr_sum += arr[i];
        }
    }
    cout << "No subArray Found";
}

void count_triplets(vector<int> arr)
{
    int count = arr.size();
    int triplets = 0;
    sort(arr.begin(), arr.end());
    for (int i = count - 1; i >= 0; i--)
    {
        int j = 0;
        int k = i - 1;
        while (j < k)
        {
            if (arr[i] == arr[j] + arr[k])
            {
                triplets++;
                j++;
                k--;
            }
            if (arr[i] > arr[j] + arr[k])
            {
                j++;
            }
            else
            {
                k--;
            }
        }
    }
    // return triplets;
}

void help_classmate(vector<int> arr)
{
    stack<pair<int, int>> st;
    vector<int> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        ans.push_back(-1);
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (st.empty())
        {
            st.push(make_pair(arr[i], i));
        }
        else
        {
            if (st.top().first <= arr[i])
            {
                st.push(make_pair(arr[i], i));
            }
            else
            {
                while (st.top().first > arr[i])
                {
                    ans[st.top().second] = arr[i];
                    st.pop();

                    if (st.empty())
                    {
                        break;
                    }
                }
            }
            st.push(make_pair(arr[i], i));
        }
    }
    for (int i = 0; i < arr.size(); i++)
    {
        cout << ans[i];
    }
}

void MaxSumSubArray(vector<int> arr)
{
    int ans = arr[0];
    int sum = 0;
    int start = 0, end = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum < 0)
        {
            sum = 0;
            start = i;
        }
        if (arr[i] > 0)
        {

            if (sum > ans)
            {
                ans = sum;
                end = i;
            }
        }
    }
    cout << ans << " " << start << " " << end;
}
void Missing_Number(vector<int> arr)
{
    int n = arr.size();
    int sum = n * (n + 1) / 2;
    int arr_sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        arr_sum += arr[i];
    }
    cout << arr_sum << "\n";
    cout << sum - arr_sum;
}

void merge1(int arr1[], int arr2[], int n, int m)
{
    // code here
    for (int i = n - 1; i >= 0; i--)
    {
        /* Find the smallest element greater than ar2[i].
        Move all elements one position ahead till the
        smallest greater element is not found */
        int j, last = arr1[m - 1];
        for (j = m - 2; j >= 0 && arr1[j] > arr2[i]; j--)
            arr1[j + 1] = arr1[j];

        // If there was a greater element
        if (j != m - 2 || last > arr2[i])
        {
            arr1[j + 1] = arr2[i];
            arr2[i] = last;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < m; i++)
    {
        cout << arr2[i];
    }
}

void RecreationalSpot(vector<int> arr)
{
    stack<int> a, b;
    a.push(arr[0]);
    b.push(arr[0]);
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] >= a.top() && arr[i] < b.top())
        {
            cout << "Yes";
            return;
        }
        if (arr[i] < a.top())
        {
            a.push(arr[i]);
        }
        else
        {
            a.push(a.top());
        }
        if (arr[i] > b.top())
        {
            b.push(arr[i]);
        }
        else
        {
            b.push(b.top());
        }
    }

    cout << "No";
}

void Candies(int m, int n)
{
    int X = (m * n) - m - n;
    unordered_set<int> hash_set;
    queue<int> queue;
    queue.push(X);
    hash_set.insert(X);

    int count = 0;
    while (queue.size() > 0)
    {
        int curr = queue.front();
        queue.pop();
        count++;

        int key = curr - m;
        if (key > 0 && (hash_set.find(key) == hash_set.end()))
        {
            queue.push(key);
            hash_set.insert(key);
        }

        key = curr - n;
        if (key > 0 && (hash_set.find(key) == hash_set.end()))
        {
            queue.push(key);
            hash_set.insert(key);
        }
    }
    cout << count;
}

void ReaarangeAlternatively(vector<int> arr)
{
    int n = arr.size();
    int i = 0;
    while (i < n)
    {
        int index = i;
        for (int j = i; j < n; j++)
        {
            int max_ele = arr[i];
            if (max_ele < arr[j])
            {
                index = j;
            }
        }
        swap(arr[i], arr[index]);
        i++;
        int index1 = i;
        for (int j = i; j < n; j++)
        {
            int min_ele = arr[i];
            if (min_ele > arr[j])
            {
                index1 = j;
            }
        }
        swap(arr[i], arr[index1]);
        i++;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void kcloset(int arr[], int n, int x, int k)
{
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(make_pair(abs(arr[i] - x), i)); // USe { } instead of make_pair function
    }
    for (int i = k; i < n; i++)
    {
        int diff = abs(arr[i] - x);

        if (diff > pq.top().first)
        {
            continue;
        }

        pq.pop();
        pq.push({diff, i});
    }
    while (!pq.empty())
    {
        cout << arr[pq.top().second] << " ";
        pq.pop();
    }
}

void Count_k(vector<int> a, int k)
{
    int rem = 0;
    int count = 0;
    int num;
    for (int i = 0; i < a.size(); i++)
    {
        num = a[i];
        rem = num % 10;
        if (rem == k)
        {
            count++;
        }
    }
    cout << count << "\n";
}

bool IsSorted(int arr[], int size)
{
    if (size == 0 || size == 1)
    {
        return true;
    }
    if (arr[0] > arr[1])
    {
        return false;
    }
    return IsSorted(arr + 1, size - 1);
}

bool IsSorted2(int arr[], int size)
{
    if (size == 0 || size == 1)
    {
        return true;
    }

    bool SmallerOutput = IsSorted2(arr + 1, size - 1);
    if (!SmallerOutput)
    {
        return false;
    }
    if (arr[0] > arr[1])
    {
        return false;
    }
    else
    {
        return true;
    }
}

int Find(int arr[], int size, int k)
{
    static int count = 0;
    int ArrSize = size;
    if (size == 0)
    {
        return -1;
    }
    if (arr[0] == k)
    {
        return count;
    }
    count++;
    Find(arr + 1, ArrSize - 1, k);
}

void FindSort(vector<int> arr)
{
    int max = INT32_MIN;
    int first_Index = 0;
    int second_index = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
            if (arr[i] > arr[i + 1])
            {
                first_Index = i;
                break;
            }
        }
    }
    for (int i = first_Index; i < arr.size(); i++)
    {
        if (max<arr[i])
        {
            max=arr[i];
            second_index=i;
        }
        
    }
}

int32_t main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << Find(a, n, k) << endl;

    // sort(arr,arr+k);
    // sort(arr+k,arr+n,greater<int>());

    // count_triplets(arr);
    // SubArraySum(arr, s);
    // vector<int> ans=help_classmate(arr);
    // help_classmate(arr);
    // MaxSumSubArray(arr);
    // Missing_Number(arr);
    // merge1(arr1, arr2, n, m);
    // RecreationalSpot(arr);
    // Candies(m, n);
    // ReaarangeAlternatively(arr);
    // kcloset(arr, n, x, k);
    return 0;
}
