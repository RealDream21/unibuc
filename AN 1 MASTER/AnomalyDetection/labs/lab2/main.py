import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import make_blobs
from sklearn.model_selection import train_test_split
from scipy.io import loadmat
from pyod.utils.data import generate_data_clusters
from pyod.models.knn import KNN
from pyod.models.lof import LOF
from pyod.utils.utility import standardizer
from pyod.models.combination import average, maximization
from sklearn.metrics import balanced_accuracy_score

# ============================================================================
# Exercise 1: Leverage Scores
# ============================================================================

def compute_leverage_scores(X):
    """Compute leverage scores for design matrix X"""
    # Add intercept column
    X_design = np.column_stack([np.ones(len(X)), X])
    # H = X(X^T X)^-1 X^T
    H = X_design @ np.linalg.inv(X_design.T @ X_design) @ X_design.T
    # Leverage scores are diagonal elements of H
    return np.diag(H)

def exercise_1():
    """Exercise 1: Leverage scores analysis"""
    print("=" * 60)
    print("Exercise 1: Leverage Scores")
    print("=" * 60)
    
    # Parameters for linear model y = ax1 + b + epsilon
    a, b = 2.5, 1.0
    noise_variances = [0.1, 0.5, 1.0, 2.0]
    n_points = 50
    
    fig, axes = plt.subplots(2, 4, figsize=(16, 8))
    fig.suptitle('Leverage Scores Analysis (1D case: y = ax + b + ε)', fontsize=14)
    
    for idx, sigma2 in enumerate(noise_variances):
        mu = 0
        sigma = np.sqrt(sigma2)
        
        # Generate regular points
        x_regular = np.random.uniform(-5, 5, n_points)
        
        # Add special points with high variance
        x_high_var = np.array([8, -8])  # High variance on x
        x_combined = np.concatenate([x_regular, x_high_var])
        
        # Generate y values
        y_regular = a * x_regular + b + np.random.normal(mu, sigma, n_points)
        y_high_var_x = a * x_high_var + b + np.random.normal(mu, sigma, 2)
        
        # High variance on y
        y_high_var_y = a * x_regular[:2] + b + np.random.normal(mu, sigma * 5, 2)
        
        # Combine all points
        X = x_combined.reshape(-1, 1)
        y = np.concatenate([y_regular, y_high_var_x])
        
        # Modify some y values for high y variance
        y[:2] = y_high_var_y
        
        # Compute leverage scores
        leverage = compute_leverage_scores(X)
        
        # Find highest leverage points
        top_indices = np.argsort(leverage)[-3:]
        
        # Plot
        ax = axes[0, idx]
        scatter = ax.scatter(X, y, c=leverage, cmap='viridis', s=50, alpha=0.6)
        ax.scatter(X[top_indices], y[top_indices], color='red', s=200, 
                  marker='*', edgecolors='black', linewidths=1.5, 
                  label='High leverage')
        ax.set_xlabel('x')
        ax.set_ylabel('y')
        ax.set_title(f'σ² = {sigma2}')
        ax.legend()
        ax.grid(True, alpha=0.3)
        plt.colorbar(scatter, ax=ax, label='Leverage')
    
    # 2D case: y = ax1 + bx2 + c + epsilon
    a2, b2, c = 1.5, 2.0, 0.5
    
    for idx, sigma2 in enumerate(noise_variances):
        mu = 0
        sigma = np.sqrt(sigma2)
        
        # Generate regular points
        x1_regular = np.random.uniform(-5, 5, n_points)
        x2_regular = np.random.uniform(-5, 5, n_points)
        
        # Add special points
        x1_high_var = np.array([8, -8])
        x2_high_var = np.array([8, -8])
        
        x1_combined = np.concatenate([x1_regular, x1_high_var])
        x2_combined = np.concatenate([x2_regular, x2_high_var])
        
        X_2d = np.column_stack([x1_combined, x2_combined])
        
        # Generate y values
        y_2d = (a2 * x1_combined + b2 * x2_combined + c + 
                np.random.normal(mu, sigma, len(x1_combined)))
        
        # Compute leverage scores
        leverage_2d = compute_leverage_scores(X_2d)
        top_indices_2d = np.argsort(leverage_2d)[-3:]
        
        # Plot
        ax = axes[1, idx]
        scatter = ax.scatter(x1_combined, x2_combined, c=leverage_2d, 
                           cmap='viridis', s=50, alpha=0.6)
        ax.scatter(x1_combined[top_indices_2d], x2_combined[top_indices_2d], 
                  color='red', s=200, marker='*', edgecolors='black', 
                  linewidths=1.5, label='High leverage')
        ax.set_xlabel('x₁')
        ax.set_ylabel('x₂')
        ax.set_title(f'σ² = {sigma2}')
        ax.legend()
        ax.grid(True, alpha=0.3)
        plt.colorbar(scatter, ax=ax, label='Leverage')
    
    plt.tight_layout()
    plt.show()
    print("\nLeverage scores identify points with high influence on the model.")
    print("Points far from the center of the data have higher leverage.\n")

# ============================================================================
# Exercise 2: KNN Anomaly Detection
# ============================================================================

def exercise_2():
    """Exercise 2: KNN with different n_neighbors"""
    print("=" * 60)
    print("Exercise 2: KNN Anomaly Detection")
    print("=" * 60)
    
    # Generate data
    X_train, X_test, y_train, y_test = generate_data_clusters(
        n_train=400, n_test=200, n_clusters=2, n_features=2,
        contamination=0.1, random_state=42
    )
    
    # Test different n_neighbors values
    n_neighbors_list = [5, 10, 20, 50]
    
    for n_neigh in n_neighbors_list:
        print(f"\n--- n_neighbors = {n_neigh} ---")
        
        # Train KNN model
        knn = KNN(n_neighbors=n_neigh, contamination=0.1)
        knn.fit(X_train)
        
        # Predictions
        y_train_pred = knn.predict(X_train)
        y_test_pred = knn.predict(X_test)
        
        # Balanced accuracy
        ba_train = balanced_accuracy_score(y_train, y_train_pred)
        ba_test = balanced_accuracy_score(y_test, y_test_pred)
        
        print(f"Training BA: {ba_train:.4f}")
        print(f"Test BA: {ba_test:.4f}")
        
        # Plot results
        fig, axes = plt.subplots(2, 2, figsize=(12, 10))
        fig.suptitle(f'KNN Results (n_neighbors={n_neigh})', fontsize=14)
        
        # Ground truth - train
        axes[0, 0].scatter(X_train[y_train == 0, 0], X_train[y_train == 0, 1], 
                          c='blue', label='Inliers', alpha=0.6, s=20)
        axes[0, 0].scatter(X_train[y_train == 1, 0], X_train[y_train == 1, 1], 
                          c='red', label='Outliers', alpha=0.6, s=20)
        axes[0, 0].set_title('Ground Truth - Training')
        axes[0, 0].legend()
        axes[0, 0].grid(True, alpha=0.3)
        
        # Predicted - train
        axes[0, 1].scatter(X_train[y_train_pred == 0, 0], X_train[y_train_pred == 0, 1], 
                          c='blue', label='Inliers', alpha=0.6, s=20)
        axes[0, 1].scatter(X_train[y_train_pred == 1, 0], X_train[y_train_pred == 1, 1], 
                          c='red', label='Outliers', alpha=0.6, s=20)
        axes[0, 1].set_title(f'Predicted - Training (BA={ba_train:.3f})')
        axes[0, 1].legend()
        axes[0, 1].grid(True, alpha=0.3)
        
        # Ground truth - test
        axes[1, 0].scatter(X_test[y_test == 0, 0], X_test[y_test == 0, 1], 
                          c='blue', label='Inliers', alpha=0.6, s=20)
        axes[1, 0].scatter(X_test[y_test == 1, 0], X_test[y_test == 1, 1], 
                          c='red', label='Outliers', alpha=0.6, s=20)
        axes[1, 0].set_title('Ground Truth - Test')
        axes[1, 0].legend()
        axes[1, 0].grid(True, alpha=0.3)
        
        # Predicted - test
        axes[1, 1].scatter(X_test[y_test_pred == 0, 0], X_test[y_test_pred == 0, 1], 
                          c='blue', label='Inliers', alpha=0.6, s=20)
        axes[1, 1].scatter(X_test[y_test_pred == 1, 0], X_test[y_test_pred == 1, 1], 
                          c='red', label='Outliers', alpha=0.6, s=20)
        axes[1, 1].set_title(f'Predicted - Test (BA={ba_test:.3f})')
        axes[1, 1].legend()
        axes[1, 1].grid(True, alpha=0.3)
        
        plt.tight_layout()
        plt.show()

# ============================================================================
# Exercise 3: KNN vs LOF
# ============================================================================

def exercise_3():
    """Exercise 3: Comparing KNN and LOF on different density clusters"""
    print("=" * 60)
    print("Exercise 3: KNN vs LOF")
    print("=" * 60)
    
    # Generate two clusters with different densities
    X1, _ = make_blobs(n_samples=200, n_features=2, centers=[(-10, -10)], 
                       cluster_std=2.0, random_state=42)
    X2, _ = make_blobs(n_samples=100, n_features=2, centers=[(10, 10)], 
                       cluster_std=6.0, random_state=42)
    X = np.vstack([X1, X2])
    
    # Test different n_neighbors values
    n_neighbors_list = [5, 20, 50]
    
    for n_neigh in n_neighbors_list:
        print(f"\n--- n_neighbors = {n_neigh} ---")
        
        # KNN
        knn = KNN(n_neighbors=n_neigh, contamination=0.07)
        knn.fit(X)
        y_pred_knn = knn.predict(X)
        
        # LOF
        lof = LOF(n_neighbors=n_neigh, contamination=0.07)
        lof.fit(X)
        y_pred_lof = lof.predict(X)
        
        print(f"KNN detected {np.sum(y_pred_knn)} outliers")
        print(f"LOF detected {np.sum(y_pred_lof)} outliers")
        
        # Plot
        fig, axes = plt.subplots(1, 2, figsize=(14, 6))
        fig.suptitle(f'KNN vs LOF (n_neighbors={n_neigh})', fontsize=14)
        
        # KNN
        axes[0].scatter(X[y_pred_knn == 0, 0], X[y_pred_knn == 0, 1], 
                       c='blue', label='Inliers', alpha=0.6, s=30)
        axes[0].scatter(X[y_pred_knn == 1, 0], X[y_pred_knn == 1, 1], 
                       c='red', label='Outliers', alpha=0.8, s=50)
        axes[0].set_title(f'KNN ({np.sum(y_pred_knn)} outliers)')
        axes[0].legend()
        axes[0].grid(True, alpha=0.3)
        
        # LOF
        axes[1].scatter(X[y_pred_lof == 0, 0], X[y_pred_lof == 0, 1], 
                       c='blue', label='Inliers', alpha=0.6, s=30)
        axes[1].scatter(X[y_pred_lof == 1, 0], X[y_pred_lof == 1, 1], 
                       c='red', label='Outliers', alpha=0.8, s=50)
        axes[1].set_title(f'LOF ({np.sum(y_pred_lof)} outliers)')
        axes[1].legend()
        axes[1].grid(True, alpha=0.3)
        
        plt.tight_layout()
        plt.show()
    
    print("\nObservation: LOF handles different density clusters better than KNN")
    print("by considering local density variations.\n")

# ============================================================================
# Exercise 4: Ensemble Methods
# ============================================================================

def exercise_4(data_path='cardio.mat'):
    """Exercise 4: Ensemble methods with KNN/LOF"""
    print("=" * 60)
    print("Exercise 4: Ensemble Methods")
    print("=" * 60)
    
    try:
        # Load data
        data = loadmat(data_path)
        X = data['X']
        y = data['y'].ravel()
        contamination = np.sum(y) / len(y)
        
        print(f"Dataset shape: {X.shape}")
        print(f"Contamination rate: {contamination:.4f}")
        
        # Split data
        X_train, X_test, y_train, y_test = train_test_split(
            X, y, test_size=0.3, random_state=42, stratify=y
        )
        
        # Normalize
        X_train, X_test = standardizer(X_train, X_test)
        
        # Test both KNN and LOF ensembles
        for model_name in ['KNN', 'LOF']:
            print(f"\n{'='*50}")
            print(f"Ensemble with {model_name}")
            print('='*50)
            
            train_scores_list = []
            test_scores_list = []
            
            # Train multiple models with different n_neighbors
            for n_neigh in range(30, 121, 10):
                if model_name == 'KNN':
                    model = KNN(n_neighbors=n_neigh, contamination=contamination)
                else:
                    model = LOF(n_neighbors=n_neigh, contamination=contamination)
                
                model.fit(X_train)
                
                # Get predictions
                y_train_pred = model.predict(X_train)
                y_test_pred = model.predict(X_test)
                
                # Balanced accuracy
                ba_train = balanced_accuracy_score(y_train, y_train_pred)
                ba_test = balanced_accuracy_score(y_test, y_test_pred)
                
                print(f"n_neighbors={n_neigh:3d} | Train BA: {ba_train:.4f} | Test BA: {ba_test:.4f}")
                
                # Store scores
                train_scores_list.append(model.decision_scores_)
                test_scores_list.append(model.decision_function(X_test))
            
            # Convert to numpy arrays
            train_scores = np.column_stack(train_scores_list)
            test_scores = np.column_stack(test_scores_list)
            
            # Normalize scores
            train_scores_norm, test_scores_norm = standardizer(train_scores, test_scores)
            
            # Average strategy
            train_scores_avg = average(train_scores_norm)
            test_scores_avg = average(test_scores_norm)
            
            threshold_avg = np.quantile(train_scores_avg, 1 - contamination)
            y_train_pred_avg = (train_scores_avg > threshold_avg).astype(int)
            y_test_pred_avg = (test_scores_avg > threshold_avg).astype(int)
            
            ba_train_avg = balanced_accuracy_score(y_train, y_train_pred_avg)
            ba_test_avg = balanced_accuracy_score(y_test, y_test_pred_avg)
            
            print(f"\n--- Average Strategy ---")
            print(f"Train BA: {ba_train_avg:.4f}")
            print(f"Test BA: {ba_test_avg:.4f}")
            
            # Maximization strategy
            train_scores_max = maximization(train_scores_norm)
            test_scores_max = maximization(test_scores_norm)
            
            threshold_max = np.quantile(train_scores_max, 1 - contamination)
            y_train_pred_max = (train_scores_max > threshold_max).astype(int)
            y_test_pred_max = (test_scores_max > threshold_max).astype(int)
            
            ba_train_max = balanced_accuracy_score(y_train, y_train_pred_max)
            ba_test_max = balanced_accuracy_score(y_test, y_test_pred_max)
            
            print(f"\n--- Maximization Strategy ---")
            print(f"Train BA: {ba_train_max:.4f}")
            print(f"Test BA: {ba_test_max:.4f}")
        
        print("\nEnsemble methods combine multiple models to improve robustness.")
        
    except FileNotFoundError:
        print(f"\nError: Could not find {data_path}")
        print("Please download the cardio dataset from:")
        print("https://odds.cs.stonybrook.edu/cardiotocogrpahy-dataset/")
        print("and place it in the same directory as this script.\n")

# ============================================================================
# Main Execution
# ============================================================================

if __name__ == "__main__":
    print("\n" + "="*60)
    print("ANOMALY DETECTION LAB 2")
    print("="*60 + "\n")
    
    # Run exercises
    exercise_1()
    exercise_2()
    exercise_3()
    
    # Exercise 4 requires external dataset
    print("\nFor Exercise 4, please ensure you have the cardio.mat file.")
    print("Uncomment the line below to run Exercise 4:")
    print("# exercise_4('cardio.mat')")
    # exercise_4('cardio.mat')  # Uncomment when dataset is available