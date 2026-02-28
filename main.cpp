#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Habit
{
private:
    string name;
    int targetDays;
    int completedDays;

public:
    Habit(string n, int t)
        : name(n), targetDays(t), completedDays(0) {}

    void markDayCompleted()
    {
        if (completedDays < targetDays)
        {
            completedDays++;
            cout << "Habit marked completed for today\n";
        }
        else
        {
            cout << "Target already acheived.\n";
        }
    }
    double getProgressPercentage() const
    {
        if (targetDays == 0)
            return 0;
        return (static_cast<double>(completedDays) / targetDays) * 100;
    }

    void display(int index) const
    {
        cout << "Habit no. " << index << endl;
        cout << "Name: " << name << endl;
        cout << "Progress: " << getProgressPercentage() << "%" << endl;
        cout << "Completed Days: " << completedDays << endl;
        cout << "Target days: " << targetDays << endl;
    }
};

class HabitTracker
{
private:
    vector<Habit> habits;

public:
    void addHabit()
    {
        string name;
        int target;

        cout << "Enter a habit name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter your target days: ";
        cin >> target;

        habits.emplace_back(name, target);
        cout << "Habit added successfully.\n";
    }

    void showHabits() const
    {
        if (habits.empty())
        {
            cout << "No habits added yet.\n";
            return;
        }
        cout << "\n=== Your Habits ===\n";
        for (int i = 0; i < habits.size(); i++)
        {
            habits[i].display(i + 1);
        }
        cout << "=====================\n";
    }

    void markHabitCompleted()
    {
        if (habits.empty())
        {
            cout << "No habits available\n";
            return;
        }
        showHabits();
        int choice;
        cout << "Select habit number to mark complete: ";
        cin >> choice;

        if (choice > 0 && choice <= habits.size())
        {
            habits[choice - 1].markDayCompleted();
        }
        else
        {
            cout << "Invalid selection.\n";
        }
    }
};

class Menu
{
private:
    HabitTracker tracker;

public:
    void show()
    {
        int choice;

        do
        {
            cout << "\n==== Habit Manager ====\n";
            cout << "1. Add Habit\n";
            cout << "2. Mark Habit Complete\n";
            cout << "3. Show Habits\n";
            cout << "4. Exit\n";
            cout << "Choose an option: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                tracker.addHabit();
                break;
            case 2:
                tracker.markHabitCompleted();
                break;
            case 3:
                tracker.showHabits();
                break;
            case 4:
                cout << " Exiting program. Stay consistent!\n";
                break;
            default:
                cout << "Invalid option. Try Again\n";
            }

        } while (choice != 4);
    }
};
int main()
{
    Menu menu;
    menu.show();
    return 0;
}