#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Job {
public:
    char id;
    int deadline;
    int profit;
    Job(char id, int deadline, int profit) : id(id), deadline(deadline), profit(profit) {}
};

bool compareJobs(const Job &j1, const Job &j2) {
    return j1.profit > j2.profit;
}

void printJobSequence(vector<Job> &jobs) {
    // Sort jobs by profit in descending order
    sort(jobs.begin(), jobs.end(), compareJobs);

    int n = jobs.size();
    int maxDeadline = 0;

    // Find the maximum deadline
    for (const Job &job : jobs) {
        if (job.deadline > maxDeadline) {
            maxDeadline = job.deadline;
        }
    }

    vector<char> result(maxDeadline, 'X'); // Stores job ids in the result sequence
    vector<bool> slot(maxDeadline, false); // Keeps track of filled time slots

    for (int i = 0; i < n; i++) {
        // Find a free slot for this job (from its deadline to the beginning)
        for (int j = min(maxDeadline - 1, jobs[i].deadline - 1); j >= 0; j--) {
            if (!slot[j]) {
                result[j] = jobs[i].id; // Assign job to this slot
                slot[j] = true;         // Mark this slot as filled
                break;
            }
        }
    }

    // Print the job sequence
    cout << "Job Sequence: ";
    for (char jobId : result) {
        if (jobId != 'X') {
            cout << jobId << " ";
        }
    }
    cout << endl;

    // Calculate the total profit
    int totalProfit = 0;
    for (int i = 0; i < maxDeadline; i++) {
        if (slot[i]) {
            for (const Job &job : jobs) {
                if (job.id == result[i]) {
                    totalProfit += job.profit;
                    break;
                }
            }
        }
    }

    cout << "Total Profit: " << totalProfit << endl;
}

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;
    
    vector<Job> jobs;
    cout << "Enter jobs in the format (id deadline profit):" << endl;
    for (int i = 0; i < n; i++) {
        char id;
        int deadline, profit;
        cin >> id >> deadline >> profit;
        jobs.emplace_back(id, deadline, profit);
    }

    printJobSequence(jobs);

    return 0;
}
