import java.util.Date;

class account{
    private int id;
    private double balance;
    private static double annualInterestRate;
    private Date dateCreated;
    private Date transactionDate;

    //no-arg constructor
    public void account(){
        id = 0;
        balance = 0;
        annualInterestRate = 0;

    }

    //constructor
    account(int newId, double someBalance){
        id = newId;
        balance = someBalance;

        getDateCreated();

        setId(id);
        setBalance(balance);

    }

    //get and set methods
        public void setId(int newId){
                id = newId;

            }
        public int getId(){
                return id;

        }
        public void setBalance(double newBalance){
                balance = newBalance;

            }
        public double getBalance(){
                return balance;

            }
        public void setAnnualInterestRate(double sAIR){
                annualInterestRate = sAIR;

            }
        public double getAnnualInterestRate(){
                return annualInterestRate;
            }
        public Date getDateCreated(){
                dateCreated = new Date();
                return dateCreated;
            }
        public Date getTransactionDate(){
            transactionDate = new Date();
            return transactionDate;
        }
        public double getMonthlyInterestRate(){
                double monthlyInterestRate = getAnnualInterestRate() / 12;
                return monthlyInterestRate;
            }
        public double getMontlyInterest(){
                double monthlyInterest = balance * getMonthlyInterestRate();
                return monthlyInterest;

            }
        public void withdraw(double amt){
            balance = balance - amt;
            setBalance(balance);

        }
        public void deposit(double amt){
            balance = balance + amt;
            setBalance(balance);

        }

}

class testAccounts {
    private static void main(String[] args) {

        account test;
        test = new account(1122, 20000);

        test.setAnnualInterestRate(.045);

        System.out.println("Account ID: " + test.getId());
        System.out.println("Date Created: " + test.getDateCreated());
        System.out.println("Account Balance: " + test.getBalance());
        System.out.println("Monthly Interest Rate: " + test.getMonthlyInterestRate());
        System.out.println("Monthly Interest: " + test.getMontlyInterest());
        System.out.println(" ");

        test.withdraw(2500);
        System.out.println("Account ID: " + test.getId());
        System.out.println("Date of Transaction: " + test.getTransactionDate());
        System.out.println("Account Balance: " + test.getBalance());
        System.out.println(" ");

        test.deposit(3000);
        System.out.println("Account ID: " + test.getId());
        System.out.println("Date of Transaction: " + test.getTransactionDate());
        System.out.println("Account Balance: " + test.getBalance());
        System.out.println(" ");


    }
}
