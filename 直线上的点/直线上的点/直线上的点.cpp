//��Ŀ����
//����N����ά�����(��������x, y, z)���ҵ�λ��ͬһ��ֱ���ϵ��������
//�������� :
//��һ�����������ĸ���N����2~N + 1������N���㣨��ʽΪ x y z����0 < N < 2000; -10000 < x, y, z < 10000
//	�������:
//λ��ͬһ��ֱ���ϵĵ��������
//ʾ��1
//����
//4
//0 0 0
//1 1 1
//- 1 - 1 - 1
//0 1 0
//���
//3
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;
struct Point3D {
	int x, y, z;
	Point3D() {}
	Point3D(int x, int y, int z)
		: x(x), y(y), z(z) {}
	bool operator==(const Point3D &pt) const {
		return x == pt.x && y == pt.y && z == pt.z;
	}
};
struct Line3D {
	// dx / dz
	float kx;
	// dy / dz
	float ky;
	// dz == 0 ?
	bool bz;
	bool operator==(const Line3D &l) const {
		return kx == l.kx && ky == l.ky && bz == l.bz;
	}
	bool operator<(const Line3D &l) const {
		return kx < l.kx || (kx == l.kx && ky < l.ky);
	}
};
namespace std {
	template <>
	struct hash<Line3D> {
		size_t operator()(const Line3D &line) const {
			size_t hash1 = 11111111;
			size_t hash2 = 4444;
			size_t hash3 = 89898989;
			return (size_t)(line.kx * hash1) + (size_t)(line.ky * hash2) +
				hash3 * (int)line.bz;
		}
	};
} // namespace std
int maxPoints(vector<Point3D> points) {
	int maxNum = 0;
	for (size_t i = 0; i < points.size(); ++i) {
		int sameNum = 0;
		int ptMaxCount = 0;
		unordered_map<Line3D, int> lineMap;
		for (size_t j = i + 1; j < points.size(); ++j) {
			auto &p1 = points[i];
			auto &p2 = points[j];
			Line3D line;
			if (p1 == p2) {
				sameNum++;
				continue;
			}
			int dz = p2.z - p1.z;
			if (dz == 0) {
				line.bz = true;
				line.kx = line.ky = 0;
			}
			else {
				line.bz = false;
				line.kx = (float)(p2.x - p1.x) / dz;
				line.ky = (float)(p2.y - p1.y) / dz;
			}
			int count;
			if (lineMap.find(line) == lineMap.end())
				count = lineMap[line] = 1;
			else
				count = ++lineMap[line];
			ptMaxCount = max(ptMaxCount, count);
		}
		maxNum = max(ptMaxCount + sameNum + 1, maxNum);
	}
	return maxNum;
}
int main() {
	int n = 0;
	scanf("%d", &n);
	vector<Point3D> points;
	while (n--) {
		Point3D p;
		scanf("%d%d%d", &p.x, &p.y, &p.z);
		points.push_back(p);
	}
	printf("%d\n", maxPoints(points));
}
