# personal-budget

Personal Budget App 📊💰

1.	Project Description	
2.	Features	
3.	Technologies	
4.	Project Structure	
	4.1. PersonalBudgetApp Class (Main Application Class)	
	4.2. User Management Module (UserManager, UsersFile)	
	4.3. Finance Management Module (BalanceManager)	
	4.4. Financial Transactions Module (OperationsFile)	
	4.5. Date Handling Module (DateMethods)	
5.	Example Usage	
6.	Author ✍️

1. Project Description
	PersonalBudgetApp is a console application for personal budget management, allowing users to control their finances by adding income and 		expenses, as well as analyzing the balance over different time periods.

	The application supports multiple users, making it useful for individuals or small groups, such as families. With a well-structured 			architecture and XML-based data storage, the application ensures data persistence between sessions.

2. Features 
	✅ User registration and login
	✅ Adding income and expenses
	✅ Viewing financial transaction history
	✅ Calculating and displaying the balance for the current and previous month
	✅ Analyzing the balance over a selected, custom period
	✅ Secure data storage in XML files

3. Technologies 
	📌 Programming Language: C++
	📌 Data Storage Format: XML
	📌 Libraries: 
		• CMarkup - XML handling
		• ctime – date operations validation
		• regex – input data validation
	📌 Object-Oriented Programming

4. Project Structure
	4.1. PersonalBudgetApp Class (Main Application Class)
		Manages the application's flow, handling user login and delegating control to relevant modules.

	Key Methods:
		• User focused:
			o loginUser(), 
			o userRegistration(), 
			o userLogout().
		• Operations focused:
			o addIncome(), 
			o addExpense().
		• Data presentation focused:
			o displayCurrentMonthBalance(), 
			o displayPreviousMonthBalance()
			o displaySelectedPeriodBalance()

	4.2.  User Management Module (UserManager, UsersFile)
		Handles user-related operations, including registration, login, and data storage in XML files.

	Key Functions:
		• User focused:
			o loginUser (), 
			o userRegistration ().
		• User data file focused:
			o loadUsersFromFile(), 
			o addUserToFile(), 
			o changeUserPassword().

	4.3. Finance Management Module (BalanceManager)
		Handles income and expenses, allows users to add transactions, and calculates financial balances.

	Key Functions:
		• User focused:
			o addIncome(), 
			o addExpense().
		• Balance calculation and display:
			o showBalance(), 
			o calculateOperationTypeBalance().

	4.4. Financial Transactions on Files Module (OperationsFile)
		Responsible for storing income and expense transactions in XML files.

	Key Functions:
		• loadOperationsOfLoggedInUserFromFile()
		• addNewOperationToFile()

	4.5. Date Handling Module (DateMethods)
		Provides utility methods for date manipulation and time range calculations.

	Key Functions:
		• getCurrentDate(),
		• getCurrentMonthFirstDayDate(),
		• getPreviousMonthFirstDayDate(),
		• getPreviousMonthLastDayDate().

5. Example Usage
	Register a new user
	📌 Provide a username, password, and personal details.
	
	Login
	📌 After entering the correct username and password, the user gains access to their financial records.
	
	Add income or expense
	📌 Users can input new financial transactions (e.g., "Salary: 5000.00", "Rent: 2000.00").
	
	4️⃣ View balance
	📌 The user can check the balance for the current month, previous month, or a custom time range.

6. Author ✍️
	📌 Creator: Kamil Szamajda (Marionmancer)
	📌 Contact: kamil.szamajda.programista@gmail.com /github.com/Marionmancer
