import subprocess
import pandas as pd
import matplotlib.pyplot as plt

def execute_a_out():
    times = []
    """Executes a.out and returns the elapsed time as an integer."""
    result = subprocess.run(['./a.out'], capture_output=True, text=True)
    # Parsing the output
    for line in result.stdout.split('\n'):
        if line.startswith('elapsed time:'):
            times.append(int(line.split(':')[1].strip()))
    return times

def process_and_plot_data(df):
    """Processes the data and plots a chart."""
    # Calculate mean for each column
    means = df.mean()

    # Plotting
    plt.figure(figsize=(10, 6))
    for i, col in enumerate(df.columns):
        plt.bar(df.index + i*0.2, df[col], width=0.2, label=f'Elapsed Time {col}')

    for i, mean in enumerate(means):
        plt.axhline(mean, color=f'C{i}', linestyle='--', label=f'Mean {i+1}: {mean:.2f}')

    plt.xlabel('Measurement Index')
    plt.ylabel('Elapsed Time')
    plt.title('Elapsed Time Measurements')
    plt.legend()

    # Save the plot as an image
    plt.savefig('elapsed_time_chart.png')
    print("Chart saved as 'elapsed_time_chart.png'.")

    # Show the plot
    plt.show()

def main():
    elapsed_times = []

    for _ in range(1000):
        times = execute_a_out()
        elapsed_times.append(times)

    # Adjust the number of columns here to match the output of execute_a_out()
    df = pd.DataFrame(elapsed_times, columns=['1', '2', '3', '4', '5'])  # Adjusted to 5 columns

    # Save to CSV
    df.to_csv('elapsed_times.csv', index=False)
    print("Elapsed times saved to 'elapsed_times.csv'.")

    # Process data and plot
    process_and_plot_data(df)

if __name__ == "__main__":
    main()

