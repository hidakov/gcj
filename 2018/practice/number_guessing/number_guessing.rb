TOO_SMALL = 'TOO_SMALL'
TOO_BIG = 'TOO_BIG'
WRONG_ANSWER = 'WRONG_ANSWER'
CORRECT = 'CORRECT'

class WrongAnswerError < StandardError; end
class TooMuchTrialError < StandardError; end

def solve(lower_limit, upper_limit, max_trial)
  #STDERR.puts "lower_limit: #{lower_limit}, upper_limit: #{upper_limit}, max_trial: #{max_trial}"
  raise TooMuchTrialError if max_trial < 1

  guess = if (lower_limit + upper_limit) % 2 == 0
    (lower_limit + upper_limit) / 2
  else
    (lower_limit + upper_limit) / 2 + 1
  end
  STDOUT.puts guess
  STDOUT.flush

  resp = STDIN.gets.chomp
  STDERR.puts "guess: #{guess}, resp: #{resp}"
  case resp
  when TOO_SMALL
    solve(guess, upper_limit, max_trial - 1)
  when TOO_BIG
    solve(lower_limit, guess - 1, max_trial - 1)
  when CORRECT
    return
  when WRONG_ANSWER
    raise WrongAnswerError
  end
end

n_case = STDIN.gets.chomp.to_i
#STDERR.puts "n_case: #{n_case}"
n_case.times do |i|
  a, b = STDIN.gets.chomp.split(' ').map(&:to_i)
  n = STDIN.gets.chomp.to_i
  STDERR.puts "##{i+1}, a: #{a}, b: #{b}, n: #{n}"
  begin 
    solve(a, b, n)
  rescue WrongAnswerError => e
    exit 1
  rescue TooMuchTrialError => e
    exit 2
  end
end
