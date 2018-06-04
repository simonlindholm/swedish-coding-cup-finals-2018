#include <bits/stdc++.h>
using namespace std;

#define double long double

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

double solve(const vector<double>& a, int K) {
	int N = sz(a);
	double res = 0;
	vector<double> pfail(N+1);
	pfail[0] = 1;
	rep(i,1,K) pfail[i] = 1 - a[i-1];
	int z = 0;
	double prod = 1;
	rep(i,0,K) {
		if (a[i] == 0) z++;
		else prod *= a[i];
	}
	rep(i,K-1,N) {
		double p = a[i];
		pfail[i+1] = (1 - res) * (1 - p);
		if (!z) res += prod * pfail[i - K + 1];
		if (i != N-1) {
			if (a[i+1] == 0) z++;
			else prod *= a[i+1];
			if (a[i-K+1] == 0) z--;
			else prod /= a[i-K+1];
		}
	}
	return res;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int N, K;
	cin >> N >> K;
	assert(1 <= K && K <= N);
	vector<double> a(N);
	rep(i,0,N) cin >> a[i];
	cout << setprecision(18) << fixed << solve(a, K) << endl;
}
