class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    
    int n = nums1.size() ;
    int m = nums2.size() ;

    nums1.resize( n );

    for ( int i = 0 ; i < m ; i++ )
    {
        nums1.push_back( nums2[i] );    
    }

    sort(nums1.begin() , nums1.end() );

    int totalSize = nums1.size();

    if( totalSize % 2 != 0 )
    {
        return nums1[ totalSize / 2 ];
    }
    else
    {
        int mid1 = nums1[ ( totalSize / 2 )  - 1 ];
        int mid2 = nums1[ ( totalSize / 2 ) ];

        return { ( mid1 + mid2 ) / 2.0 };
    }
    }
};