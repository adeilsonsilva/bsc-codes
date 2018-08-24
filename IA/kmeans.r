get_centroids <- function(dataset, centroids, labels) {
    tmp_centroids <- centroids
    for (i in 1:length(tmp_centroids)) {
        # Get every observation with a label
        obs <- dataset[which(labels == centroids[i]),]
        if (nrow(obs) > 0) {
            # Get mean of those observations
            mi <- apply(obs, 2, mean)
            # Get which one of observations is
            # closest to mean
            raw_distances <- as.matrix(dist(rbind(obs, mi)))
            distances <- raw_distances[2:nrow(raw_distances),1]
            if (distances == 0) {
                # mi == obs
                tmp_centroids[i] <- rownames(obs)
            } else {
                tmp_centroids[i] <- names(distances)[which.min(distances)]
            }
        } else {
            # If no observation has that centroid as a label, we reinitialize it
            tmp_centroids[i] <- sample(1:nrow(dataset), 1, replace=FALSE)
        }

    }

    return(tmp_centroids)
}

get_labels <- function(dataset, centroids) {
    tmp_labels <- numeric(nrow(dataset))
    for (i in 1:nrow(dataset)) {
        # Get distance from observation to all centroids
        raw_distances <- as.matrix(dist(rbind(dataset[i,], dataset[centroids,])))
        # Keep only distances from observation to centroids
        distances <- raw_distances[2:nrow(raw_distances),1]
        # Save the minimum centroid distance as the label for that observation
        tmp_labels[i] <- names(distances)[which.min(distances)]
    }
    return(tmp_labels)
}

k_means <- function(dataset, K = 10, iterations = 100) {
    # Get number of features
    features <- ncol(dataset)

    # Each observation has a label
    labels <- numeric(nrow(dataset))

    # As we want K clusters, each one has a centroid
    # Get K random centroids from all observations
    centroids <- sample(1:nrow(dataset), K, replace=FALSE)
    old_centroids <- c(0)

    for (observation in 1:iterations) {
        cat("* Iteration:", observation, "\n")
        if (all(centroids == old_centroids)) {
            cat("\t+ CONVERGED!")
            break;
        }
        old_centroids <- centroids
        labels <- get_labels(dataset, centroids)
        centroids <- get_centroids(dataset, centroids, labels)
        cat("\t**", centroids, "\n")
    }

    result <- list()
    result$centroids <- centroids
    result$labels <- labels

    return(result)
}

# Load data
db <- read.csv("abalone.data", header=TRUE)

clusters <- k_means(db[1:500,2:9], K=29, iterations = 10)
View(clusters)
r <- kmeans(db[1:500,2:9], centers = 29)
View(r)
