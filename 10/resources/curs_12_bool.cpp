// Ilie Dumitru
#include<cstdio>
#include<cstring>
const int NMAX=1005;

int N;
char s[NMAX];
int Q;
char op[NMAX];
bool truth[26];

// In functiile recursive de mai jos parametrul este mereu primul caracter neprocesat
bool expresie(int& i);
bool termen(int& i);
bool factor(int& i);
bool constanta(int& i);
bool variabila(int& i);

bool variabila(int& i)
{
	return truth[s[i++] - 'A'];
}

bool constanta(int& i)
{
	bool rez = (s[i] == 'T');
	i += 5 - rez;
	return rez;
}

bool factor(int& i)
{
	if(s[i] == '(')
	{
		// Trec de (
		++i;

		bool rez = expresie(i);

		// Trec de )
		++i;

		return rez;
	}

	if(s[i] == 'N' && s[i + 1] == 'O')
	{
		i += 3;

		return !factor(i);
	}

	if(s[i + 1] == 'R' || (s[i] == 'F' && s[i + 1] == 'A'))
		return constanta(i);

	return variabila(i);
}

bool termen(int& i)
{
	bool F = factor(i);

	while(i < N && s[i] == 'A')
	{
		i += 3;

		F &= factor(i);
	}

	return F;
}

bool expresie(int& i)
{
	bool T = termen(i);

	while(i < N && s[i] == 'O')
	{
		i += 2;

		T |= termen(i);
	}

	return T;
}

int main()
{
	FILE* f = fopen("bool.in", "r"), *g = fopen("bool.out", "w");
	int i, j;

	// Citire + asigurare ca nu exista \n la sfarsit
	fgets(s, NMAX, f);
	N = strlen(s);
	if(s[N - 1] == '\n')
		s[--N] = 0;

	// Eliminarea spatiilor
	for(i = j = 1;i < N;++i)
		if(s[i] != ' ')
			s[j++] = s[i];
	N = j;

	// Citire operatii
	fscanf(f, "%d", &Q);
	fgets(op, NMAX, f);
	fgets(op, NMAX, f);

	// Afisare
	for(i = 0;i < Q;++i)
	{
		truth[op[i] - 'A'] ^= 1;
		j = 0;
		fprintf(g, "%d", (int)expresie(j));
	}

	fclose(f);
	fclose(g);
	return 0;
}