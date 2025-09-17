struct cmp {
    bool operator()(const pair<int, string>& p1, const pair<int, string>& p2) const {
        if (p1.first == p2.first)
            return p1.second < p2.second;
        return p1.first > p2.first;       
    }
};

class FoodRatings {
    unordered_map<string, pair<int, string>> foodMap;
    unordered_map<string, multiset<pair<int, string>, cmp>> maxRating;
    
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            foodMap[foods[i]] = {ratings[i], cuisines[i]};
            maxRating[cuisines[i]].insert({ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto currFood = foodMap[food];
        int prevRating = currFood.first;
        string cuss = currFood.second;
        
        maxRating[cuss].erase(maxRating[cuss].find({prevRating, food}));
        maxRating[cuss].insert({newRating, food});
        foodMap[food].first = newRating;
    }
    
    string highestRated(string cuisine) {
        return maxRating[cuisine].begin()->second;
    }
};
