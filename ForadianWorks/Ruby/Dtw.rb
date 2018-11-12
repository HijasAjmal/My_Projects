
#Ruby Program to convert given date to words

class Dtw
  #Array off Strings of digits in words
  @@a = {1 => "FIRST",  2 => "SECOND",  3 => "THIRD",  4 => "FOURTH",  5 => "FIFTH",  6 => "SIXTH",  7 => "SEVENTH",  8 => "EIGTH",  9 => "NINETH",
  10 => "THENTH",  11 => "ELEVENTH",  12 => "TWELVETH",  13 => "THIRTEENTH",  14 => "FOURTEENTH",  15 => "FIFTEENTH",  16 => "SIXTEENTH",  17 => "SEVENTEETH",
  18 => "EIGTEENTH",  19 => "NINETEENTH"}
  @@y ={1 => "ONE", 2 => "TWO", 3 => "THREE", 4 => "FOUR", 5 => "FIVE", 6 => "SIX", 7 => "SEVEN", 8 => "EIGHT", 9 => "NINE", 10 => "TEN", 11 => "ELEVEN",
    12 => "TWELVE",  13 => "THIRTEEN",  14 => "FOURTEEN",  15 => "FIFTEEN",  16 => "SIXTEEN",  17 => "SEVENTEEN",
  18 => "EIGHTEEN",  19 => "NINETEEN", 20 => "TWENTY",}
  @@b = {2 => "TWENTY",  3 => "THIRTY",  4 => "FORTY",  5 => "FIFTY",  6 => "SIXTY",  7 => "SEVENTY",  8 => "EIGHTY",  9 => "NINETY"}
  @@m = {1 => "January",  2 => "February",  3 => "March",  4 => "April",  5 => "May",  6 => "June",  7 => "July",  8 => "Augest",  9 => "September", 10 => "October",
    11 => "November", 12 => "Dcember"}
  @@c = ["HUNDRED",  "THOUSAND"]

  #Main method
  def input_method
    puts "Enter the Date in Format (dd-mm-yyyy)::"
    @date = gets.to_s
    @date_to_type = @date.split("-")
    is_valid(@date_to_type[2], @date_to_type[1], @date_to_type[0])
    date(@date_to_type[0])
    month(@date_to_type[1])
    year(@date_to_type[2])
  end


  #method to validate the given date
  def is_valid(year, month, date)
    @yearnew = year.to_i
    @month = month.to_i
    @date = date.to_i
    if @month > 0 && @month < 13 && @date <= 31
      if @month == 2
        if @yearnew % 400 == 0 && @date <= 29
          return true
        elsif @yearnew % 4 == 0 && @yearnew % 100 != 0 && @date <= 29
          return true
        elsif @date <= 28
          return true
        else
          err_code
        end
      elsif @month == 4 || @month == 6 ||	@month == 9 || @month == 11 && @date > 30
        err_code
      end
    else
      err_code
    end
  end


  #exit code generation if the date is not valid
  def err_code
    puts "Your date is not valid............!"
    Kernel.exit
  end


  #convert the date
  def date(dt)
    @dtnew = dt.to_i
    if @dtnew >= 20
      print "#{@@b[@dtnew/10]}"
      print " #{@@a[@dtnew%10]}" if  @dtnew%10 != 0
    else
      print "#{@@a[@dtnew]}"
    end
  end

  #convert the month
  def month(mt)
    @dtnew = mt.to_i
    print "-#{@@m[@dtnew]}"
  end
  #convert the year
  def year(yr)
    @dtnew = yr.to_i
    print "-#{@@y[@dtnew/1000]}"
    print " #{@@c[1]} " if @@y[@dtnew/1000] != nil
    @newyr = @dtnew%1000
    loop do
      if @newyr < 100
        print " #{@@y[@newyr]}" if @newyr <= 20
        print "#{@@b[@newyr/10]}" if @newyr > 20
        print " #{@@y[@newyr%10]}" if  @newyr%10 != 0 && @newyr > 20
        break
      else
        print " #{@@y[@newyr/100]}"
        print " #{@@c[0]} "
        @newyr = @newyr%100
      end
    end
  end
end

#object of the class Dtw
ob = Dtw.new

#call the function input_method()
ob.input_method
