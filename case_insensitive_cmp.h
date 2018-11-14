
// Subtask 3: Case insensitive compare
// Write bool operator( ) in a reasonable fashion! Making a lower case
// copy of the strings, and using < is not reasonable!
struct case_insensitive_cmp {
	bool operator()(const std::string& lhs, const std::string& rhs) const
	{
		auto len = (lhs.size() < rhs.size()) ? lhs.size() : rhs.size();
		for(size_t i = 0; i<len; ++i)
			if (std::tolower(lhs[i]) != std::tolower(rhs[i]))
				return std::tolower(lhs[i]) < std::tolower(rhs[i]);

		return lhs.size() < rhs.size();
	}
};

