Fixed project notes:
- Removed duplicate main() functions from admin.cpp, member.cpp and Employee.cpp so that Functions.cpp remains the single entry point.
- Changed writing to requests.txt and employee_reports.txt to append mode to avoid overwriting.
- Added helper containsAvailable() in Functions.h to perform case-insensitive availability checks.
- Updated device.txt entries to use 'Working'/'Not working' and 'Available'/'Not available' consistently.
- Removed unsafe delete calls that could delete uninitialized pointers.
- You should still review further refactors: prefer stack allocation instead of raw new/delete, add input validation, error checks for stoi, and consider using CSV parser or structured storage for robustness.
