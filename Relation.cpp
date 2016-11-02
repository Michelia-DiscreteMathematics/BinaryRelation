#include "Relation.h"
using namespace std;

Relation::Relation(){
}

Relation::~Relation(){
	bin.clear();
}

void Relation::get_rows_and_cols(){
	cout<<"Please type the number of the variables for your Relation:";
	(cin>>row_col).get();
	initialize_binary(row_col);	//楼下那个函数的调用在这呢！
}

void Relation::initialize_binary(int r){	//虽然函数名为初始化，但实际上是展开动态数组
	bin.resize(r);
	for (int i = 0; i < r; ++i){bin[i].resize(r);}
	putin.resize(r);	//准备接受二元关系矩阵的输入
}

void Relation::get_binary_relation(){
	cout<<"Now you can type in your binary-relation,"<<endl;
	cout<<"as a result of this programming using a matrix to record the relation,"<<endl;
	cout<<"Please type in a matrix, just using '0' and '1', type in one line at a time"<<endl;
	for (int i = 0; i < row_col; ++i)
	{
		if (i==0){cout<<"Please type the 1st row:";}
		else if (i==1){cout<<"Please type the 2nd row:";}
		else {cout<<"Please type the "<<i+1<<"rd row:";}
		getline(cin,putin[i]);
	}
}

void Relation::input_format(){
	for (int r = 0; r < row_col; ++r){
		char str[putin[r].size()+1];
		char * p = (char *)putin[r].c_str();
		strcpy(str,p);
		char q[row_col+1];
		for (int i = 0; i < row_col; ++i){q[i]='0';}
		q[row_col]='\0';
		p = str;
		for (int i=0;*(p+i)!='\0';++i){
			if(!((*(p+i)=='1'||*(p+i)=='0'))){
				for(int j=i;*(p+j)!='\0';++j){*(p+j)=*(p+j+1);}
				--i;	//退格！
			}
		}
		for (int i=0;*(p+i)!='\0';++i){q[i]=p[i];}
		putin[r] = q;
	}
	//就是个测试
}

void Relation::assignment_binary(){
	for (int i = 0; i < row_col; ++i){
		for (int j = 0; j < row_col; ++j){
			if (putin[i][j] == '1'){bin[i][j] = true;}
			else {bin[i][j] = false;}
		}
	}
}

void Relation::reflexivity_judgement(){
	bool value = true;
	for (int i = 0; i < row_col; ++i){
		if (!(bin[i][i])){value = false;}
	}
	reflexivity = value;
}

void Relation::symmetry_judgement(){
	bool value = true;
	for (int i = 0; i < row_col; ++i){
		for (int j = i; j < row_col; ++j){
			if (bin[i][j]^bin[j][i]){value = false;}
		}
	}
	symmetry = value;
}

void Relation::transitivity_judgement(){	//时间复杂度非常高，但是别的方法我实在想不出来，凑合用吧
	bool value = true;
	bool ergodic = false;
	std::vector<int> start,end;
	for (int i = 0; i < row_col; ++i){
		for (int j = 0; j < row_col; ++j){
			if (bin[i][j]){
				for (int k = 0; k < row_col; ++k){
					if (bin[j][k]){	//找出所有应该存在的序偶对
						start.push_back(i);
						end.push_back(k);
					}
				}
			}
		}
	}
	for (int i = 0; i < start.size(); ++i){
		if (!(bin[start[i]][end[i]])){value = false;}
	}
	transitivity = value;
}

void Relation::anti_reflexivity_judgement(){
	bool value = true;
	for (int i = 0; i < row_col; ++i){
		if ((bin[i][i])){value = false;}
	}
	anti_reflexivity = value;
}

void Relation::anti_symmetry_judgement(){
	bool value = true;
	for (int i = 0; i < row_col; ++i){
		for (int j = i+1; j < row_col; ++j){
			if (bin[i][j]&&bin[j][i]){value = false;}
		}
	}
	anti_symmetry = value;
}

void Relation::matrix_print(){
	cout<<"┌";
	for (int i = 0; i < row_col; ++i){cout<<"   ";}
	cout<<"┐"<<endl;
	for (int i = 0; i < row_col; ++i){
		cout<<"│";
		for (int j = 0; j < row_col; ++j){cout<<" "<<putin[i][j]<<" ";}
		cout<<"│"<<endl;
	}
	cout<<"└";
	for (int i = 0; i < row_col; ++i){cout<<"   ";}
	cout<<"┘"<<endl;
}

void Relation::relation_print(){
	// for (int i = 0; i < row_col; ++i){
	// 	for (int j = 0; j < row_col; ++j){
	// 		cout<<putin[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	cout<<"reflexivity: ";
	if (reflexivity){cout<<"Yes."<<endl;}
	else{cout<<"No."<<endl;}
	cout<<"symmetry: ";
	if (symmetry){cout<<"Yes."<<endl;}
	else{cout<<"No."<<endl;}
	cout<<"transitivity: ";
	if (transitivity){cout<<"Yes."<<endl;}
	else{cout<<"No."<<endl;}
	cout<<"anti_reflexivity: ";
	if (anti_reflexivity){cout<<"Yes."<<endl;}
	else{cout<<"No."<<endl;}
	cout<<"anti_symmetry: ";
	if (anti_symmetry){cout<<"Yes."<<endl;}
	else{cout<<"No."<<endl;}

}