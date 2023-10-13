#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

int get_leftmost_end_index(vector<Segment> &segments, vector<bool> visited_segments) {
	int res = -1;
	long long comp = INFINITY;
	for(int i=0; i < segments.size(); i++) {
		if(visited_segments[i]) continue;
		if(segments[i].end < comp) {
			comp = segments[i].end;
			res = i;
		}
	}

	return res;
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
	vector<bool> visited_segments(segments.size(), false);
  
	int i=0;
	while(i < segments.size()) {
		int seg_index = get_leftmost_end_index(segments, visited_segments);
		Segment seg = segments[seg_index];
		
		// verify if is already covered;
		bool isCovered = false;
		for(int j=0; j < points.size(); j++) {
			if(seg.start <= points[j] && seg.end >= points[j]) {
				isCovered = true;
				break;
			}
		}
		if(!isCovered) {
			points.push_back(seg.end);
		}
		visited_segments[seg_index] = true;
		i++;
	}

  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }

  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
