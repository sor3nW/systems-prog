BEGIN {
    callCount = 0
    FS = ","
    
}
{
    
    
    callCount += 1
    split($2, dateTime, " ")
    date=substr( dateTime[1], 2, length(dateTime[1])-1)
    time=substr( dateTime[2], 1, length(dateTime[2])-1)
    
    
    if (date in datesArr){
        firstCallTime = firstCallTimeArr[date]
        lastCallTime = lastCallTimeArr[date]
        if (time < firstCallTime){
            firstCallTimeArr[date] = time
            firstCallArr[date] = $0
        }
        if (time > lastCallTime){
            lastCallTimeArr[date] = time
            lastCallArr[date] = $0
        }
    } else {
        firstCallTimeArr[date] = time
        firstCallArr[date] = $0
        lastCallTimeArr[date] = time
        lastCallArr[date] = $0
        datesArr[date] = date
    }
    
    if ($3 in problemTypes){
        problemTypes[$3] += 1
    } else {
        problemTypes[$3] = 1
    }

    if ($5 in divisions){
        divisions[$5] += 1
    } else {
        divisions[$5] = 1
    }
}
END{
    print "Total calls = " callCount
    for(date in datesArr){
        print "\nDate: " date
        print "\tFirst Call: " firstCallArr[date]
        print "\tLast Call: " lastCallArr[date]
    }
    print "\nPer-Problem Totals: " 
    for (problemType in problemTypes){
        print "\t" problemType ": " problemTypes[problemType]
    }
    print "\nPer-Division Totals: "
    for (division in divisions){
        print "\t" division ": " divisions[division]
    }
}
