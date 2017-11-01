// define :	a,b...x,y,z
// such as :	(a=-10,b=-9.....x=8,y=9,z=10)

// result = 
// while x,y,z >= 0 :		x*y*z
// while y,z>=0 && x<0 :	a*b*z
// while z>=0 && x,y<0 :	a*b*z
// while x,y,z < 0 :		x*y*z

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        
        // sort(nums.begin(),nums.end());
        
        // get x, y, z
        for( int i=0 ; i<3 ; i++ ) {
            for( int j=0 ; j<n-1-i ; j++ ) {
                if( nums[j] > nums[j+1] ) {
                    int t = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = t;
                }
            }
        }
        
        // get a, b
        for( int i=0 ; i<2 ; i++ ) {
            for( int j=n-1 ; j>0+i ; j-- ) {
                if( nums[j-1] > nums[j] ) {
                    int t = nums[j];
                    nums[j] = nums[j-1];
                    nums[j-1] = t;
                }
            }
        }
        
        // choose max
        // x, y, z
        int ret1 = nums[n-1] * nums[n-2] * nums[n-3];
        // a, b, z
        int ret2 = nums[n-1] * nums[0] * nums[1];
        
        return ret1 > ret2 ? ret1 : ret2;
    }
};
