#include <iostream>

const size_t NR = 8;
const size_t NC = 8;

void initMatrix(int[][NR]);
void spiroMatrix(int[][NR], size_t _nr, size_t _nc, int _val, size_t _iterCounter = 0);
void showMatrix(int[][NR]);

int main()
{
	int m[NR][NC];

	initMatrix(m);
	spiroMatrix(m, NR, NC, 1);
	showMatrix(m);

	return 0;
}

void initMatrix(int _m[][NR])
{
	for (size_t nr = 0; nr < NR; nr++)
	{
		for (size_t nc = 0; nc < NC; nc++)
		{
			_m[nr][nc] = 0;
		}
	}
}

void spiroMatrix(int _m[][NR], size_t _NR, size_t _NC, int _val, size_t _iterCounter)
{
	for (size_t nc = 0 + _iterCounter; nc < _NC - _iterCounter; nc++)
	{
		_m[0 + _iterCounter][nc] = _val++;
	}

	for (size_t nr = 1 + _iterCounter; nr < _NR - _iterCounter; nr++)
	{
		_m[nr][_NC - 1 - _iterCounter] = _val++;
	}

	for (size_t nc = _NC - 2 - _iterCounter; nc > 0 + _iterCounter; nc--)
	{
		_m[_NR - 1 - _iterCounter][nc] = _val++;
	}
	_m[_NR - 1 - _iterCounter][_iterCounter] = _val++;

	for (size_t nr = _NC - 2 - _iterCounter; nr > 0 + _iterCounter; nr--)
	{
		_m[nr][0 + _iterCounter] = _val++;
	}

	if (_val <= NR * NC)
	{
		showMatrix(_m);
		std::cout << "===========================================" << std::endl;
		spiroMatrix(_m, NR, NC, _val, ++_iterCounter);
	}
}

void showMatrix(int _m[][NR])
{
	using namespace std;

	for (size_t nr = 0; nr < NR; nr++)
	{
		for (size_t nc = 0; nc < NC; nc++)
		{
			cout << "\t" << _m[nr][nc];
		}
		cout << endl;
	}
	cout << endl;
}
