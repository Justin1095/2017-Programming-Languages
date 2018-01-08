#Justin Seda
#Programing Languages CPSC 330
#Reads in the file called data.txt, the file's format for each line: record number| size | username | transaction | field type | numeric_value | character_value |date_value |
#The program uses regular expressions and checks field type first. The field type's values can only be N, C, or D. If the value is N then there can only be a numeric_value. 
#If it is C then there can only be a character_value. Lastly if it is D then there can only be a data_value.
#It will check each line and if some thing is wrong then it will explain what is it 

use v5.24.1;
use warnings;
my $counter = 1;
open FILE, "data.txt" or die "Could not out file"; #gets file 
while(my $row = <FILE>) #goes through the rows in the file 
{
	chomp $row;
	if($row =~ /12[|]15[|]joe[|]2[|]N[|][\-]?[0-9]{1,2}[\. | 0][^.]/) #see if the row is correct for numeric field
	{
		print"line $counter OK --- $row\n";
	}
	elsif($row =~ /12[|]15[|]joe[|]2[|]C[|]\s[|][a-z][|]\s/)#see if the row is correct for character field
	{
		print"line $counter OK --- $row\n";
	}
	elsif($row =~ /12[|]15[|]joe[|]2[|]D[|]\s[|]\s[|]([0][1-9]|[1][0-2])[\/]([0-2][1-9]|[3][0-1])[\/]\d\d\d\d/)#see if the row is correct for date field
	{
		print"line $counter OK --- $row\n";
	}
	elsif($row =~ /12[|]15[|]joe[|]2[|]D[|]\s[|]\s[|][0-9]{1,2}?[\/]([0-2][1-9]|[3][0-1])[\/]\d\d\d\d/) #states that the line is incorrect for date field
	{
		print"line $counter NO --- $row\n";
		print"Field type D does not have a valid date.\n";
		print"The months should only be from 1 to 12.\n"; #the error is within the months, only from 1 to 12
	}
	elsif($row =~ /12[|]15[|]joe[|]2[|]D[|]\s[|]\s[|]([0-9][0-9])[\/][0-9]{1,2}[\/]\d\d\d\d/)#states that the line is incorrect for date field
	{
		print"line $counter NO --- $row\n";
		print"Field type D does not have a valid date.\n";
		print"The days should only be from 1 to 31.\n" #the error is within the days, only from 1 to 31
	}
	elsif($row =~ /12[|]15[|]joe[|]2[|]D[|]\s[|]\s[|]/)#states that the line is incorrect for date field
	{
 		print"line $counter NO --- $row\n";
		print"Field type D does not have a valid date.\n";
		print"There should be no other characters or empty spaces besides mm/dd/yyyy.\n" #the error is within the characters and empty spaces
	}
	else #states that the line is incorrect for anything else that was not accepted within the other statements
	{
		print"line $counter N0 --- $row\n";
	}
	
	$counter++;
}
close FILE;
print"\n"