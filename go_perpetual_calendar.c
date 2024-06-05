package main  
  
import (  
	"bufio"  
	"fmt"  
	"os"  
	"strconv"  
	"strings"  
)  
  
var daysInMonth = []int{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}  
  
func isLeapYear(year int) bool {  
	return (year%4 == 0 && year%100 != 0) || (year%400 == 0)  
}  
  
func firstDayOfMonth(year, month int) int {  
	offset := (year-1900)*365 + (year-1901)/4 - (year-1901)/100 + (year-1901)/400  
	for i := 1; i < month; i++ {  
		offset += daysInMonth[i-1]  
		if i == 2 && isLeapYear(year) {  
			offset++  
		}  
	}  
	return (offset + 1) % 7  
}  
  
func printCalendar(year int) {  
	fmt.Printf("Calendar for the year %d:\n\n", year)  
  
	for month := 1; month <= 12; month++ {  
		if month == 2 && isLeapYear(year) {  
			daysInMonth[1]++  
		}  
		fmt.Printf("Month %d:\n", month)  
		fmt.Printf("   Sun Mon Tue Wed Thu Fri Sat\n")  
		fmt.Println("-------------------------------")  
		day := 1  
		weekday := firstDayOfMonth(year, month)  
		for day <= daysInMonth[month-1] {  
			for i := 0; i < weekday; i++ {  
				fmt.Print("   ")  
			}  
			fmt.Printf("%3d ", day)  
			day++  
			weekday = (weekday + 1) % 7  
			if weekday == 0 {  
				fmt.Println()  
			}  
		}  
		fmt.Println()  
		if month == 2 && isLeapYear(year) {  
			daysInMonth[1]--  
		}  
	}  
}  
  
func main() {  
	reader := bufio.NewReader(os.Stdin)  
	fmt.Print("Enter a year: ")  
	input, _ := reader.ReadString('\n')  
	input = strings.TrimSpace(input)  
	year, _ := strconv.Atoi(input)  
  
	printCalendar(year)  
}
