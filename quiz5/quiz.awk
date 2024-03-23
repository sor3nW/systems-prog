
BEGIN {
    gradeCount=0;
    gradeTotal=0;
    failingCount=0;
}
{
    if ($3 == section) {
        print $2, $1, $5, $4;
        gradeCount++
        gradeTotal = gradeTotal + $5
        if ($5 <= 60) {
            failingCount++;
        }
    }
}
END {
    print "Average grade:", gradeTotal / gradeCount;
    print "Failing grades:", failingCount;
}