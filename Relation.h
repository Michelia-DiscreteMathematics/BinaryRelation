#include <iostream>
#include <string>
#include <vector>
#include <cmath>

class Relation
{
private:
	int row_col;
	bool reflexivity = false;
	bool symmetry = false;
	bool transitivity = false;
	bool anti_reflexivity = false;
	bool anti_symmetry = false;
	std::vector<std::vector<bool>> bin;
	std::vector<std::string> putin;

public:
	Relation();
	~Relation();
	void get_rows_and_cols();
	void initialize_binary(int r);
	void get_binary_relation();
	void input_format();
	void assignment_binary();
	void reflexivity_judgement();	//判断自反性
	void symmetry_judgement();	//判断对称性
	void transitivity_judgement();	//判断传递性
	void anti_reflexivity_judgement();	//判断反自反性
	void anti_symmetry_judgement();	//判断反对称性
	void matrix_print();	//输出矩阵
	void relation_print();	//输出性质判断结果

};