// Ilie Dumitru
#include<fstream>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<algorithm>

struct folder
{
	std::map<std::string, folder*> dirs;
	std::multiset<std::string> files;
};

std::string s;
int cntFiles;
std::vector<std::string> paths;

void process(int& i, folder* F)
{
	std::string aux;

	while(i < (int)s.size() && s[i] != ')')
	{
		if(s[i] >= 'A' && s[i] <= 'Z')
		{
			aux = "";
			while(s[i] != '(')
				aux += s[i++];
			++i;
			F->dirs[aux] = new folder();
			process(i, F->dirs[aux]);
			++i;

			if(F->dirs[aux]->dirs.empty() && F->dirs[aux]->files.empty())
			{
				delete F->dirs[aux];
				F->dirs.erase(F->dirs.find(aux));
			}
		}
		else if(s[i] >= 'a' && s[i] <= 'z')
		{
			++cntFiles;
			aux = "";
			while(i < (int)s.size() && s[i] != ')' && s[i] != ',')
				aux += s[i++];
			F->files.insert(aux);
		}
		else
			++i;
	}
}

void load(folder* F, std::string path)
{
	std::string aux;

	for(std::pair<const std::string, folder*>& p : F->dirs)
	{
		aux = path;
		aux += p.first;
		aux += '\\';
		load(p.second, aux);
	}
	for(const std::string& s : F->files)
	{
		paths.push_back(path);
		paths.back() += s;
	}
}

int main()
{
	std::ifstream f("dir.in");
	std::ofstream g("dir.out");
	folder F;
	int i = 0;

	getline(f, s);
	process(i, &F);
	g << cntFiles << '\n';
	load(&F, "");

	std::sort(paths.begin(), paths.end());
	for(i = 0;i < (int)paths.size();++i)
		g << paths[i] << '\n';

	return 0;
}