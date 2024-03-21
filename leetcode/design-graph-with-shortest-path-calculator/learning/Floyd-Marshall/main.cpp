#include<vector>
#include<iostream>
#include<chrono>
#include<memory>
#include<climits>
#include<cstring>

using namespace std;

static void problem_uptr(vector<vector<int>> &edges, size_t n) {

	auto matrix = make_unique<unique_ptr<int[]>[]>(n);
	for (size_t i = 0; i < n; i++) {
		matrix[i] = make_unique<int[]>(n);
		for (size_t j = 0; j < n; j++)
			matrix[i][j] = INT_MAX;
		matrix[i][i] = 0;
	}

}

static void problem_int_d2(vector<vector<int>> &edges, size_t n) {

	int **matrix = new int*[n];
	for (size_t i = 0; i < n; i++) {
		matrix[i] = new int[n];
		for (size_t j = 0; j < n; j++)
			matrix[i][j] = INT_MAX;
		matrix[i][i] = 0;
	}

	for (size_t i = 0; i < n; i++)
		delete [] matrix[i];
	delete [] matrix;

}
static void problem_builtin_vector(vector<vector<int>> &edges, size_t n) {
	vector<vector<int>> vv(n, vector<int>(n, INT_MAX));
}
static void problem_weird_vector(vector<vector<int>> &edges, size_t n) {

	vector<vector<int>> v2(n);
	for (size_t i = 0; i < n; i++) {
		vector<int>	v(n);
		v2[i] = v;
		for (size_t j = 0; j < n; j++)
			v2[i][j] = !!(j - i) * INT_MAX;
	}

}
static void problem_vector_manually(vector<vector<int>> &edges, size_t n) {

	vector<vector<int>> v3(n);
	for (size_t i = 0; i < n; i++) {
		vector<int>	v(n);
		v3[i] = v;
		for (size_t j = 0; j < n; j++) {
			v3[i][j] = INT_MAX;
		v3[i][i] = 0;
		}
	}

}

int main() {
	std::vector<std::vector<int>> edges = {
		{1, 2, 3},
		{2, 3, 5},
		{3, 4, 2},
		{4, 1, 1},
		{1, 3, 10},
		{1, 2, 3},
		{2, 3, 5},
		{3, 4, 2},
		{4, 1, 1},
		{1, 3, 10},
		{1, 2, 3},
		{2, 3, 5},
		{3, 4, 2},
		{4, 1, 1},
		{1, 3, 10},
		{1, 2, 3},
		{2, 3, 5},
		{3, 4, 2},
		{4, 1, 1},
		{1, 3, 10},
		{1, 2, 3},
		{2, 3, 5},
		{3, 4, 2},
		{4, 1, 1},
		{1, 3, 10},
		{1, 2, 3},
		{2, 3, 5},
		{3, 4, 2},
		{4, 1, 1},
		{1, 3, 10},
		{1, 2, 3},
		{2, 3, 5},
		{3, 4, 2},
		{4, 1, 1},
		{1, 3, 10},
		{1, 2, 3},
		{2, 3, 5},
		{3, 4, 2},
		{4, 1, 1},
		{1, 3, 10},
		{1, 2, 3},
		{2, 3, 5},
		{3, 4, 2},
		{4, 1, 1},
		{1, 3, 10},
		{1, 2, 3},
		{2, 3, 5},
		{3, 4, 2},
		{4, 1, 1},
		{1, 3, 10},
		{1, 2, 3},
		{2, 3, 5},
		{3, 4, 2},
		{4, 1, 1},
		{1, 3, 10},
		{1, 2, 3},
		{2, 3, 5},
		{3, 4, 2},
		{4, 1, 1},
		{1, 3, 10},
		{1, 2, 3},
		{2, 3, 5},
		{3, 4, 2},
		{4, 1, 1},
		{1, 3, 10},
		{1, 2, 3},
		{2, 3, 5},
		{3, 4, 2},
		{4, 1, 1},
		{1, 3, 10},
		{1, 2, 3},
		{2, 3, 5},
		{3, 4, 2},
		{4, 1, 1},
		{1, 3, 10},
		{1, 2, 3},
		{2, 3, 5},
		{3, 4, 2},
		{4, 1, 1},
		{1, 3, 10},
		{1, 2, 3},
		{2, 3, 5},
		{3, 4, 2},
		{4, 1, 1},
		{1, 3, 10}
    };
	size_t n = edges.size();

	//UNIQUE PTR
	auto start_time = std::chrono::high_resolution_clock::now();
	problem_uptr(edges, n);
	auto end_time = std::chrono::high_resolution_clock::now();
	cout << "elapsed time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count() << endl;

	start_time = std::chrono::high_resolution_clock::now();
	problem_int_d2(edges, n);
	end_time = std::chrono::high_resolution_clock::now();
	cout << "elapsed time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count() << endl;

	start_time = std::chrono::high_resolution_clock::now();
	problem_builtin_vector(edges, n);
	end_time = std::chrono::high_resolution_clock::now();
	cout << "elapsed time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count() << endl;

	start_time = std::chrono::high_resolution_clock::now();
	problem_weird_vector(edges, n);
	end_time = std::chrono::high_resolution_clock::now();
	cout << "elapsed time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count() << endl;

	start_time = std::chrono::high_resolution_clock::now();
	problem_vector_manually(edges, n);
	end_time = std::chrono::high_resolution_clock::now();
	cout << "elapsed time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count() << endl;

	return 0;
}
