// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//      vector<int> temp;
//      int N = nums.size();
//      k = k % N;

//     if (N <= 1 )
//     {
//         return;
//     }

//      if ( k == 0 )
//         return ;

//     for (int i =  N - k ; i < N; i++)
//     {
//         temp.push_back( nums[i] );
//     }

//         //shift original elements to the right (loop backwards to avoid overwriting)
//         for (int i = N - k - 1; i >= 0; i--) {
//             nums[i + k] = nums[i];
//         }

//         // putthe temp elements back into the FRONT of the array
//         for (int i = 0; i < k; i++) {
//             nums[i] = temp[i];
//         }

//     }
// };


class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n = nums.size();

        k = k % n;

        reverse( nums.begin() , nums.end() );

        reverse(nums.begin() , nums.begin() + k );

        reverse(nums.begin() + k , nums.end() );
    }
};