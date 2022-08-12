class Solution {
public:
    
int groupUnion[1001];

int findUnion(int i) {
	if (groupUnion[i] != i)
		groupUnion[i] = findUnion(groupUnion[i]);
	return groupUnion[i];
}
    
void makeUnion(int changePosition, int i) {
    if(changePosition != groupUnion[changePosition]){
        makeUnion(groupUnion[changePosition],i);
    }
    groupUnion[changePosition] = i;
}

vector<vector<string>> accountsMerge(vector<vector<string>>& accountList) {
    int accountListSize = accountList.size();
    
	for (int i = 0; i < accountListSize; i++) {
		groupUnion[i] = i;
	}

    unordered_map<string, int> emailGroup;

    for (int i = 0; i < accountListSize; i++) {
        int accountSize = accountList[i].size();

        for (int j = 1; j < accountSize; j++) {
            string email = accountList[i][j];
            string accountName = accountList[i][0];

            if (emailGroup.find(email) == emailGroup.end()) {
                emailGroup[email] = i;
            }
            else {
                makeUnion(emailGroup[email], i);
            }
        }
    }

	for (int i = 0; i < accountListSize; i++) {
		findUnion(i);
	}


    unordered_map<int, vector<string>> components;
    for (auto emailIterator : emailGroup) {
        string email = emailIterator.first;
        int group = groupUnion[emailIterator.second];
        components[group].push_back(email);
    }

    
    vector<vector<string>> mergedAccounts;
    for (auto componentIterator : components) {
        int group = componentIterator.first;
        vector<string> component = { accountList[group][0] };
        component.insert(component.end(), componentIterator.second.begin(),
            componentIterator.second.end());
        sort(component.begin() + 1, component.end());
        mergedAccounts.push_back(component);
    }

    return mergedAccounts;
}
};