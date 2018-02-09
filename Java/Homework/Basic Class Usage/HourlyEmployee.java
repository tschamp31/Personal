public class HourlyEmployee {
    private String name = "None";
    private String ssn;
    private double hourlyRate = 15.0;
    private int hoursWorked;

    public HourlyEmployee(String n, String s, double hRate) {
        System.out.println("New 1");
        this.name = n; this.ssn = s; this.hourlyRate = hRate;

    }

    public HourlyEmployee(String n, String s) {
        System.out.println("New 2");
        this.name = n; this.ssn = s;

    }

    public HourlyEmployee() {
        System.out.println("New 3");
        this.name = "Not Provided"; this.ssn = "Not Provided"; this.hourlyRate = 10.0;

    }

    public String GetEmployeeInfo() {
        return name + "," + ssn + "," + hourlyRate + "," + hoursWorked; }
    }

    public static void main(String[] args)
    {
        public static void main(String[] args) {
            HourlyEmployee obj1 = new HourlyEmployee();   //Line1
            HourlyEmployee obj2 = new HourlyEmployee("Seema", "111-11-1111"); //Line 2
            HourlyEmployee obj3 = new HourlyEmployee("Yaji", "222-22-2222", 20); //Line 3  
            System.out.println(obj1.GetEmployeeInfo()); //Line 4
            System.out.println(obj2.GetEmployeeInfo()); //Line 5
            System.out.println(obj3.GetEmployeeInfo()); //Line 6
        }
     }