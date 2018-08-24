# This file is part of ADell.
#
# ADell is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# ADell is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with ADell  If not, see <https://www.gnu.org/licenses/>.



# Activation function for neural network
# We are using a binary step function
# @param  numeric   number        Number to be evaluated
# @param  numeric   threshold     Threshold to be used
activate <- function(number, threshold) {
    return(as.numeric(number > threshold))
}

# Main neural network function
# @param  data.frame   dataset      Matrix of data to be trained on
# @param  vector       labelset     List of data labels
# @param  numeric      threshold    Threshold to be used in activation function
# @param  numeric      lrate        Learning rate
# @param  numeric      iterations   Max number of iterations to be performed
# @return list         result       List of final weights, bias and threshold
perceptron <- function(dataset, labelset, threshold=0.5, lrate=0.1, iterations=150)
{
    # Initialize weights, bias and error as 0
    weights <- numeric(ncol(dataset))
    bias <- 0
    error <- 0

    # Main loop
    for (i in 1:iterations) {
        cat("* Iteration:", i, "\n")
        # Pick a random example
        j <-floor(runif(1, min=1, max=nrow(dataset) + 1))
        # Weighted sum of input
        u <- sum(dataset[j,] * weights) + bias
        # Calculate output
        y <- activate(u, threshold)
        # Update weights
        weights <- weights + lrate * (labelset[j] - y) * dataset[j,]
        bias <- bias + lrate * (labelset[j] - y)
        # Calculate error
        # error <- sum(abs(labelset - y)) / ncol(dataset)
        #if (i > 1 && error < threshold) {
        #    cat("IT CONVERGED! - ", bias, "***", error, "\n")
        #    break
        #}
        error <- error + abs(labelset[j] - y) / i
        cat("- BIAS:", bias, " ***  ERROR:", error, "\n")
    }

    result <- list()
    result$weights <- weights
    result$bias <- bias
    result$error <- error

    return(result)
}

# Function to evaluated trained model
# @param    list    model   Model obtained from perceptron function
# @param    data.frame  dataset    Data to be evaluated
# @param    numeric threshold   Threshold for activation function
test <- function(model, dataset, threshold) {
    y <- activate(sum(model$weights * dataset) + model$bias, threshold)
    return(y)
}

# EXAMPLE
# Load data
db <- read.csv("data.csv", header=FALSE, sep=";")

# Train ANN
model <- perceptron(db[,1:3], db[,4], iterations = 10)

# Test trained model
cat("*** TESTING ***", "\n")
print(test(model, c(0, 0, 0), 0.5))
print(test(model, c(1, 0, 0), 0.5))
print(test(model, c(0, 1, 0), 0.5))
print(test(model, c(0, 0, 1), 0.5))
print(test(model, c(1, 1, 0), 0.5))
print(test(model, c(1, 0, 1), 0.5))
print(test(model, c(0, 1, 1), 0.5))
print(test(model, c(1, 1, 1), 0.5))
