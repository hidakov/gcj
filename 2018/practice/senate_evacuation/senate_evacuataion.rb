class SenatorCounter
  Letters = ('A'..'Z').to_a

  def self.index_to_letter(idx)
    Letters[idx]
  end

  def initialize(num_senators_list)
    @list = num_senators_list.dup
  end

  def sum
    @sum ||= @list.reduce(0) do |accum, i|
      accum += i
      accum
    end
  end

  def has_absolute_majority?
    n, idx = biggest
    n > sum / 2
  end

  def biggest
    n_senators = 0
    idx_of_biggest = -1
    @list.each_with_index do |current, idx|
      if n_senators < current
        n_senators = current
        idx_of_biggest = idx
      end
    end
    
    [n_senators, idx_of_biggest]
  end

  def decrement(idx)
    new_list = @list.dup
    new_list[idx] -= 1
    self.class.new(new_list)
  end
end

def solve(num_senators_list)
  ans = []
  counter = SenatorCounter.new(num_senators_list) 
  while(counter.sum > 0)
    num1, idx1 = counter.biggest 
    counter = counter.decrement(idx1)

    num2, idx2 = counter.biggest 
    tmp = counter.decrement(idx2)
    if tmp.has_absolute_majority?
      ans << SenatorCounter.index_to_letter(idx1)
    else
      ans << SenatorCounter.index_to_letter(idx1) + SenatorCounter.index_to_letter(idx2)
      counter = tmp
    end
  end

  ans.join(' ')
end

n_cases = STDIN.gets.chomp.to_i
n_cases.times do |i|
  n_parties = STDIN.gets.chomp.to_i
  num_senators_list = STDIN.gets.chomp.split(' ').map(&:to_i)

  ans = solve(num_senators_list)
  puts "Case ##{i+1}: #{ans}"  
end
