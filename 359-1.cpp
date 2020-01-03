class Logger {
public:
    /* Initialize your data structure here. */
    Logger() {}

    /* Returns true if the message should be printed in the given timestamp, otherwise return false.
     * If this method returns false, the message will not be printed.
     * The timestamp is in seconds granularity.
     */
    bool shouldPrintMessage(int timestamp, string message) {
        if (print_times.count(message) && 
            timestamp - print_times[message] < 10)
            return false;
        print_times[message] = timestamp;
        return true;
    }
private:
    unordered_map<string, int> print_times;
};

/*
 * Whether it should print the message depends on the timestamp it was printed last time.
 * Therefore, we need to record its last printing time.
 */
