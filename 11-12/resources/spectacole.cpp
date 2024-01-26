#include <algorithm>
#include <fstream>
#include <utility>
#include <vector>

std::ifstream fin("spectacole.in");
std::ofstream fout("spectacole.out");

int main () {
    int n; fin >> n;
    std::vector<std::pair<int, int>> spectacole(n);
    for (int i = 0; i < n; i += 1)
        fin >> spectacole[i].second >> spectacole[i].first;

    std::sort (spectacole.begin (), spectacole.end ());

    int res = 1, last = 0;
    for (int i = 1; i < n; i += 1)
        if (spectacole[i].second >= spectacole[last].first)
            res += 1, last = i;

    fout << res;
    return 0;
}
