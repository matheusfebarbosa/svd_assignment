#include <map>
#include <string>
#include <vector>

using namespace std;

class Dataset{

private:
	double **ratings_;
	vector<pair<pair<int,int>,double>> train_;
	vector<pair<pair<int,int>,double>> test_;
	map<string,int> users_encode_;
	map<string,int> items_encode_;
	vector<string> users_;
	vector<string> items_;
	int n_items_;
	int n_users_;


	void init_ratings(int r, int c);

public:
	Dataset(){

	}

	Dataset(string path, double train_test){
		load_ratings(path, train_test);
	}

	~Dataset(){
		// for (int i = 0; i < n_users_; i++){
		//     delete [] ratings_[i];
		// }
		//delete [] ratings_;
	}

	void load_ratings(string path, double train_test);
	double** ratings();
	int n_users();
	int n_items();
	int encode_user(string user);
	int encode_item(string item);
	vector<pair<pair<int,int>,double>> test();
	vector<pair<pair<int,int>,double>> train();

};