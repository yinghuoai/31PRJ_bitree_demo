class Solution{
	
	public:
	
	
	bool anagram(string s,string t){
		
		if(s.empty() || t.empty()   )
		{
			return false;
			
		}
		
		if(s.size() != t.size()  )
		{
			
			return false;
			
		}
		
		int letterCount[256] = {0};

		for(int i = 0;  i != s.size(); ++i)
		{
			++letterCount[s[i]];
			--letterCount[t[i]];
			
			
		}
		
		for(int i = 0;i != t.size();++i)
		{
			if(lettCount[t[i]]  != 0)
			{
				return false;
				
			}
				
			
		}
		
		
		return true;
		
		
		
	}
	
	
	
	
	
}








