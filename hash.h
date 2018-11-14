// Subtask 5:
struct case_insensitive_hash {
	size_t operator()( const std::string& s ) const
	{
		std::string lwr{s};
		std::transform(lwr.begin(), lwr.end(), lwr.begin(), ::tolower);
		std::hash<std::string> hf;
		return hf(lwr);
	}
	/*
	{
         size_t h = 0;
         for( size_t i = 0; i != s. length( ); ++ i ) 
         {
            h = h * 1001 + s[i];
         }
         return h;
        }*/
};

struct case_insensitive_equality {
	bool operator()( const std::string& s1, const std::string& s2 ) const
	{
		auto len = (s1.size() < s2.size()) ? s1.size() : s2.size();
		for (size_t i = 0; i<len; ++i) {
			if ( !(tolower(s1[i]) == tolower(s2[i])) ) return false;
		}
		return true;
	} 
};

