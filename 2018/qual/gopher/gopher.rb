class WrongAnswerError < StandardError; end
class TooMuchDeploymentError < StandardError; end

class Memo 
  def initialize
    @prepared = {}
    @num_prepared_in_block = {}
  end

  def candidate_position(max_i: , max_j:)
    i_range = 2..max_i
    j_range = 2..max_j

    candidate_i = 2
    candidate_j = 2
    min = 9
    i_range.each do |i|
      j_range.each do |j|
        n = num_prepared_in_block(i: i, j: j)
        if n == 0
          return [i, j]
        elsif n == 9
          next
        elsif n < min
          candidate_i = i
          candidate_j = j
          min = n
        end
      end
    end

    [candidate_i, candidate_j]
  end

  def num_prepared_in_block(i:, j:)
    @num_prepared_in_block[[i, j]].to_i
  end

  def prepare!(i:, j:)
    unless prepared?(i: i, j: j)
      i_range = (i-1)..(i+1)
      j_range = (j-1)..(j+1)
      i_range.each do |ii|
        j_range.each do |jj|
          tmp_key = [ii, jj]
          @num_prepared_in_block[tmp_key] = 0 if @num_prepared_in_block[tmp_key].nil?
          @num_prepared_in_block[tmp_key] += 1 
        end
      end
    end
    @prepared[[i, j]] = true
  end

  def prepared?(i:, j:)
    if @prepared[[i,j]]
      true
    else
      false
    end
  end
end

def solve(area, max_deployment)
  max_candidate_i, max_candidate_j = if area == 10
    [2, 3]
  elsif area == 20
    [3, 4]
  elsif area == 200
    [13, 14]
  end
  memo = Memo.new

  cnt = 0
  done = false
  while !done 
    raise TooMuchDeploymentError if cnt >= max_deployment 

    i, j = memo.candidate_position(max_i: max_candidate_i, max_j: max_candidate_j)
    STDOUT.puts "#{i} #{j}" 
    STDOUT.flush

    resp_i, resp_j = STDIN.gets.chomp.split(' ').map(&:to_i)
    STDERR.puts "position: #{i} #{j}, resp_i: #{resp_i}, resp_j: #{resp_j}"
    if resp_i == -1 and resp_j == -1
      raise WrongAnswerError
    elsif resp_i == 0 and resp_j == 0
      done = true
    else
      memo.prepare!(i: resp_i, j: resp_j)
    end

    cnt += 1
  end
end

n_case = STDIN.gets.chomp.to_i
n_case.times do |i|
  a = STDIN.gets.chomp.to_i
  STDERR.puts "a: #{a}"
  begin 
    solve(a, 1000)
  rescue WrongAnswerError => e
    exit 1
  rescue TooMuchDeploymentError => e
    exit 2
  end
end
