next_accountno = 0
class Account:

   def __init__(self, name, deposit):
      global next_accountno
      self.name = name
      self.balance = deposit
      self.account_no=next_accountno
      next_accountno += 1
   

   def displayAccount(self):
      print "Name : ", self.name,  ", Salary: ", self.balance, ", Account No: ", self.account_no

   def update_balance(amount):
      self.balance+=amount
x=Account("krishna",5000)
y=Account("krishna",5000)
x.displayAccount()
y.displayAccount()