#include "iostream"  
#include "string"  
#include "vector"  
using namespace std;
std::vector<char> common;
int lcs(string A, string B){
	std::vector<vector<int> > len;
	len.resize(A.size() + 1);
	for (int i = 0; i <= A.size(); i++){
		len[i].resize(B.size() + 1, 0);
	}
	for (int i = 1; i <= A.size(); ++i)
	{
		for (int j = 1; j <= B.size(); ++j)
		{
			if (A[i - 1] == B[j - 1])
			{
				len[i][j] = len[i - 1][j - 1] + 1;
			}
			else if (len[i - 1][j] >= len[i][j - 1])
			{
				len[i][j] = len[i - 1][j];
			}
			else{
				len[i][j] = len[i][j - 1];
			}
		}
	}
	int apos = A.size();
	int bpos = B.size();
	int commonlen = len[apos][bpos];
	int k = commonlen;
	common.resize(commonlen);
	while (apos && bpos){
		if (len[apos][bpos] == len[apos - 1][bpos] + 1){
			common[--k] = A[--apos];
			--bpos;
		}
		else if (len[apos - 1][bpos] >= len[apos][bpos - 1])
		{
			--apos;
		}
		else{
			--bpos;
		}
	}
	for (int i = 0; i < commonlen; i++){
		cout << common[i];
	}
	cout << endl;
	return commonlen;
}
int main(int argc, char const *argv[])
{

	string A, B;
	cout << "请输入字符串A：";
	cin >> A;
	cout << "请输入字符串A：";
	cin >> B;
	cout << "最长公共子序列为：";
	cout << "最长公共子序列长度为："<<lcs(A, B)<<endl;
	return 0;
}