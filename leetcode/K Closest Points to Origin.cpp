class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<pair<int,pair<int,int> > > ordered;
        for(int i=0;i<points.size();i++){
            int dist = points[i][0] * points[i][0] + points[i][1]*points[i][1];
            cout << dist << endl;
            ordered.push_back(make_pair(dist,make_pair(points[i][0],points[i][1])));
        }
        sort(ordered.begin(),ordered.end());
        vector<vector<int> > ret;
        for(int i=0;i<K;i++){
            vector<int> tmp;
            tmp.push_back(ordered[i].second.first);
            tmp.push_back(ordered[i].second.second);
            ret.push_back(tmp);
        }
        return ret;
    }
};