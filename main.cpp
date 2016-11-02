#include "Relation.h"
using namespace std;

int main(){
	Relation rel;
	rel.get_rows_and_cols();
	rel.get_binary_relation();
	rel.input_format();
	rel.assignment_binary();	//到这里二元关系矩阵的构建就完成了w
	rel.matrix_print();
	rel.reflexivity_judgement();
	rel.symmetry_judgement();
	rel.transitivity_judgement();
	rel.anti_reflexivity_judgement();
	rel.anti_symmetry_judgement();
	rel.relation_print();
	return 0;
}