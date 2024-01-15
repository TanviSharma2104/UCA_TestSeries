class Solution {
    public int lengthOfLongestSubstring(String A) {
        
        int[] charIndex = new int[256]; // Assuming ASCII characters

        Arrays.fill(charIndex, -1); // Initialize all characters' last index as -1
        int start = -1;
        int maxLength = 0;

        for(int i=0;i<A.length();i++){
            char curr=A.charAt(i);
            if(charIndex[curr]>start){
                start=charIndex[curr];
            }
            charIndex[curr]=i;
            maxLength=Math.max(maxLength,i-start);
        }
       
        return maxLength;
    }
}
