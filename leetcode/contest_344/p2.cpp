class FrequencyTracker {
   public:
    unordered_map<int, int> nums;
    unordered_map<int, int> freq;
    FrequencyTracker() {}

    void add(int number) {
        nums[number]++;
        freq[nums[number]]++;
        freq[nums[number] - 1]--;
    }

    void deleteOne(int number) {
        if (nums[number] <= 0) return;
        nums[number]--;
        freq[nums[number]]++;
        freq[nums[number] + 1]--;
    }

    bool hasFrequency(int frequency) { return freq[frequency] > 0; }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */