# Hypothesis Testing - Paired t-test (or Wilcoxon test if non-normal)

if (Normality_Results_1_Night$p.value > 0.05 &
Normality_Results_2_Nights$p.value > 0.05) {
print("Data is normally distributed. Performing Paired t-test.")
t_test_result <- t.test(driving_score_data$`1 night of sleep deprivation`,
driving_score_data$`2 nights of sleep deprivation`, paired = TRUE)
print(t_test_result)
} else {
print("Data is not normally distributed. Performing Wilcoxon Signed-Rank
Test.")
wilcox_result <- wilcox.test(driving_score_data$`1 night of sleep
deprivation`, driving_score_data$`2 nights of sleep deprivation`, paired =
TRUE)
print(wilcox_result)
}