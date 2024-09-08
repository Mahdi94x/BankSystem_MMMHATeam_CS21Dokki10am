#ifndef PARSER_H
#define PARSER_H

class Parser
{
    public:
	static vector<vector<string>> split(string dataBulk) {
		vector<vector<string>> allData;
		string line;
		stringstream ss(dataBulk);

		// Split the bulk data into individual lines
		while (getline(ss, line, '\n')) {
			vector<string> singleLineAttributes;
			string token;
			stringstream lineStream(line);

			// Split each line into attributes based on the '#' delimiter
			while (getline(lineStream, token, '~')) {
				singleLineAttributes.push_back(token);
			}

			// Add the vector of attributes to the main vector
			singleLineAttributes.shrink_to_fit();
			allData.push_back(singleLineAttributes);

		}
		return allData;
	}

	static Client parseToClient(vector<string> singleLineAttributes) {}
	static Employee parseToEmployee(vector<string> singleLineAttributes) {}
	static Admin parseToAdmin(vector<string> singleLineAttributes) {}
};

#endif // PARSER_H
